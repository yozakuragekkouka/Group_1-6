#pragma once
#include "Scene.h"
#include "../../Oda/Sound/Sound.h"

#define START_IMG_SIZE_X 400
#define START_IMG_SIZE_Y 66

//oda
class SceneTitle : public SceneBase
{
private:
	// マウスカーソル座標
	int MouseX;
	int MouseY;

	// 画像ハンドル
	int TitleBGHandle;
	int StartHandle;
	int ProvideHandle;

	// State画像の座標
	int StartPosX;
	int StartPosY;

	// 画像サイズ
	float imgSize;

	// 透明度変数
	int Transparency;

	// 大きさ変更判定
	bool isChangeSize;

	// 透明度判定
	bool isTrans;

	// タイトルシーンのサウンドハンドル
	int TitleSoundHandle[TITLESOUND_MAX_NUM];

public:
	SceneTitle();
	~SceneTitle();

	void Init();

	void Step();

	void Draw();

	void Fin();

	// マウス接触処理
	void MouseContact();

	// 大きさ変更処理
	void ChangeSize();

	// 透明度変数処理
	void TransparencyProcessing();

	// マウスの当たり判定の処理
	bool MouseCollision();

	// タイトルシーンのファイル読み込み
	void LoadSoundTitle();

	// タイトルシーンのファイル破棄
	void DeleteSoundTitle();
};
