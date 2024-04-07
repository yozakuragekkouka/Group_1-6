#include "DxLib.h"
#include "../../Common.h"
#include "SceneTitle.h"
#include "Scene.h"
#include "../Input/Input.h"
#include "../../Oda/Collision/Collision.h"

//oda
SceneTitle::SceneTitle()
{
	// マウスカーソル座標
	MouseX = 0;
	MouseY = 0;

	// 画像ハンドル
	TitleBGHandle = 0;
	StartHandle = 0;
	ProvideHandle = 0;

	// State画像の座標
	StartPosX = 0;
	StartPosY = 0;

	// 画像サイズ
	imgSize = 0;

	// 透明度変数
	Transparency = 0;

	// 大きさ変更判定
	isChangeSize = 0;

	// 透明度判定
	isTrans = 0;

	// サウンドハンドル
	for (int SoundIndex = 0; SoundIndex < TITLESOUND_MAX_NUM; SoundIndex++)
	{
		TitleSoundHandle[SoundIndex] = 0;
	}
}
SceneTitle::~SceneTitle(){}

//タイトル初期化
void SceneTitle::Init()
{
	// 画像ハンドル
	TitleBGHandle = LoadGraph("Data/Oda/BackGround/Title.png");
	StartHandle = LoadGraph("Data/Oda/Title/Start.png");
	ProvideHandle = LoadGraph("Data/Oda/Title/MusMus.png");

	// State画像の座標
	StartPosX = SCREEN_SIZE_X / 2;
	StartPosY = SCREEN_SIZE_Y - SCREEN_SIZE_Y / 4;

	// 画像サイズ
	imgSize = 1.0f;

	// 透明度変数
	Transparency = 256;

	// 大きさ変更判定
	isChangeSize = false;

	// 透明度判定
	isTrans = false;

	// サウンドハンドル
	for (int SoundIndex = 0; SoundIndex < TITLESOUND_MAX_NUM; SoundIndex++)
	{
		TitleSoundHandle[SoundIndex] = 0;
	}

	// ファイル読み込み
	LoadSoundTitle();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_TITLE;
}

//タイトル通常処理
void SceneTitle::Step()
{
	// マウス接触処理
	MouseContact();

	// 大きさ変更処理
	ChangeSize();

	// 透明度変数処理
	TransparencyProcessing();
}

//タイトル描画処理
void SceneTitle::Draw()
{
	// タイトル画像表示
	DrawGraph(0, 0, TitleBGHandle, true);

	// Stareボタン画像表示
	// 透明度が変わる
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Transparency);
	DrawRotaGraph(StartPosX, StartPosY, imgSize, 0.0f, StartHandle, false, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// 提供画像表示
	DrawGraph(0, SCREEN_SIZE_Y - 55, ProvideHandle, true);

	// Debug用
	/*
	DrawFormatString(0, 0, GetColor(255, 0, 0), "%d", MouseX);
	DrawFormatString(0, 25, GetColor(255, 0, 0), "%d", MouseY);
	DrawBox(StartPosX - 175, StartPosY - 30, StartPosX - 175 + START_IMG_SIZE_X - 50, StartPosY - 30 + START_IMG_SIZE_Y - 6, GetColor(255, 0, 0), TRUE);
	*/
}

//タイトル後処理
void SceneTitle::Fin()
{
	// マウスカーソル座標
	MouseX = 0;
	MouseY = 0;

	// 画像ハンドル
	TitleBGHandle = 0;
	StartHandle = 0;
	ProvideHandle = 0;

	// State画像の座標
	StartPosX = 0;
	StartPosY = 0;

	// 画像サイズ
	imgSize = 0;

	// 透明度変数
	Transparency = 0;

	// 大きさ変更判定
	isChangeSize = 0;

	// 透明度判定
	isTrans = 0;

	// ファイル破棄
	DeleteSoundTitle();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_PLAY;
}

// マウス接触処理
void SceneTitle::MouseContact()
{
	// マウスカーソル座標を取得
	GetMousePoint(&MouseX, &MouseY);

	// マウスが接触していたら
	if (MouseCollision() == true)
	{
		isChangeSize = true;
		isTrans = true;

		// 左クリックが押されている場合
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			PlaySoundMem(TitleSoundHandle[TITLE_SERECT_SE], DX_PLAYTYPE_BACK, true);
			Sleep(250);
			SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_TITLE;
		}
	}
	// マウスが接触していなかったら
	else
	{
		isChangeSize = false;
		isTrans = false;
	}
}

// 大きさ変更処理
void SceneTitle::ChangeSize()
{
	// 大きさ変更判定が真なら
	if (isChangeSize == true) {
		// 画像サイズを1.0にする
		imgSize = 1.0f;
	}

	// 大きさ変更判定が偽なら
	if (isChangeSize == false) {
		// 画像サイズを0.8にする
		imgSize = 0.9f;
	}
}

// 透明度変数処理
void SceneTitle::TransparencyProcessing()
{
	// 透明度判定が真なら
	if (isTrans == true) {
		// 透明度変数を256にする
		Transparency = 256;
	}

	// 透明度判定が偽なら
	if (isTrans == false) {
		// 透明度変数を128にする
		Transparency = 160;
	}
}

// マウスの当たり判定の処理
bool SceneTitle::MouseCollision()
{
	// State画像とマウスカーソルが当たっているか
	if (Collision::Rect_Dot(StartPosX - START_IMG_SIZE_X / 2 - 25, StartPosY - START_IMG_SIZE_Y / 2 - 6,
							START_IMG_SIZE_X - 50, START_IMG_SIZE_Y - 6,
							MouseX, MouseY))
	{
		return true;
	}

	return false;
}

// タイトルシーンのファイル読み込み
void SceneTitle::LoadSoundTitle()
{
	// BGMの読み込み
	TitleSoundHandle[TITLE_BGM] = LoadSoundMem(TITLE_BGM_PATH);
	// BGMを再生
	PlaySoundMem(TitleSoundHandle[TITLE_BGM], DX_PLAYTYPE_LOOP, true);

	TitleSoundHandle[TITLE_SERECT_SE] = LoadSoundMem(SELECT_SE_PATH);
}

// タイトルシーンのファイル破棄
void SceneTitle::DeleteSoundTitle()
{
	for (int SoundIndex = 0; SoundIndex < TITLESOUND_MAX_NUM; SoundIndex++)
	{
		DeleteSoundMem(TitleSoundHandle[SoundIndex]);
	}
}