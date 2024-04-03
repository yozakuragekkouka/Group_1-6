#include <math.h>
#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../Shapes/Shapes.h"
#include "Scene.h"
#include "SceneResult.h"
#include "../NumberFont/NumberFont.h"

//クリア初期化
void SceneResult::Init()
{
	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_RESULT;
}

//クリア通常処理
void SceneResult::Step()
{
	if (Input::PressAnyKey())
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_RESULT;
	}
}

//クリア描画処理
void SceneResult::Draw()
{
}

//クリア後処理
void SceneResult::Fin()
{
	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_TITLE;
}
