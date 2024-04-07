#include <math.h>

#include "DxLib.h"
#include "../../Common.h"
#include "../FrameRate/FrameRate.h"
#include "../Input/Input.h"

#include "../Score/ScoreManager/ScoreManager.h"

#include "Scene.h"
#include "ScenePlay.h"

//プレイシーン初期化
void ScenePlay::Init()
{
	gameState = GameState::Continue;
	now_playerNumber = 0;

	ScoreManager::Init();
	ScoreManager::SetAll_playerNum();

	interval.Init();
	minigame_manager.Init();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void ScenePlay::Step()
{
	if (interval.GetState() == IntervalState::Playing_MiniGame)
	{
		minigame_manager.Step();
		if (minigame_manager.Get_MiniGameisFinish())
		{
			if (minigame_manager.Get_MiniGameisClear())
			{
				gameState = GameState::Continue;
				ScoreManager::AddScore(now_playerNumber, 1);
			}
			else
			{
				gameState = GameState::GameOver;
			}

			now_playerNumber++;
			if (now_playerNumber >= ScoreManager::GetAll_playerNum())
			{
				now_playerNumber = 0;
			}

			interval.SetState(IntervalState::End_MiniGame);
		}
	}
	else
	{
		switch (gameState)
		{
		case GameState::Continue:
			if (interval.GetState() == IntervalState::Stay_MiniGame)
			{
				interval.Step();
				if (interval.GetState() == IntervalState::Start_MiniGame)
				{
					minigame_manager.MiniGameFin();
					minigame_manager.Delete_Game();
					minigame_manager.Set_NewGame();

					minigame_manager.MiniGameInit();
				}
			}
			else
				interval.Step();
			break;
		case GameState::GameOver:
			interval.End_Step();
			if(interval.GetAll_Fin())
				SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_PLAY;
			break;
		}
	}
	if (Input::PressAnyKey())
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_PLAY;
	}
}

//プレイシーン描画処理
void ScenePlay::Draw()
{
	interval.Draw();
	minigame_manager.Draw();
}

//プレイシーン後処理
void ScenePlay::Fin()
{
	interval.Fin();
	minigame_manager.Fin();
	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_RESULT;
}
