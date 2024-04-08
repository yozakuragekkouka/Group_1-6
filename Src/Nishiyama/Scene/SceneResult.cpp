#include <math.h>
#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../Shapes/Shapes.h"
#include "../NumberFont/NumberFont.h"
#include "Scene.h"
#include "SceneResult.h"
#include "../Score/ScoreManager/ScoreManager.h"

//クリア初期化
void SceneResult::Init()
{
	BG_Image.RectInit(LoadGraph(RESULT_BG_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);
	playerImage.RectInit(LoadGraph(RESULT_PLAYER_PATH), VGet((float)(SCREEN_SIZE_X / 2) + 300.0f, (float)SCREEN_SIZE_Y - 100.0f, 0.0f), 128, 128);

	scoreFont.Init();
	scoreFont.SetNumberFont(Number_16_32_black);
	scoreFont.Set_posX(SCREEN_SIZE_X / 2);
	scoreFont.Set_posY(SCREEN_SIZE_Y / 2);

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_RESULT;
}

//クリア通常処理
void SceneResult::Step()
{
	if (Input::ClickRect(BG_Image))
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_RESULT;
	}
}

//クリア描画処理
void SceneResult::Draw()
{
	BG_Image.DrawRect();
	playerImage.DrawRect_Rota_Center();

	scoreFont.Draw_int(ScoreManager::GetScore(0), true, true);
}

//クリア後処理
void SceneResult::Fin()
{
	BG_Image.RectFin();
	playerImage.RectFin();

	scoreFont.Fin();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_TITLE;
}
