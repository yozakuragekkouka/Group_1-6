#include "MiniGameManager.h"
#include "../MiniGame_shuu/SearchGame/SearchGame.h"
#include "../../../Shimizu/Barrage/Barrage.h"
#include "../../../Shimizu/JustStop/JustStop.h"
#include "../../../Shimizu/RapidPress/RapidPress.h"


void MiniGameManager::Init()
{
	miniGame = nullptr;
}

void MiniGameManager::Step()
{
	if (miniGame != nullptr)
	{
		miniGame->Step();
	}
}

void MiniGameManager::Draw()
{
	if (miniGame != nullptr)
	{
		miniGame->Draw();
	}
}

void MiniGameManager::Fin()
{
	if (miniGame != nullptr)
	{
		delete miniGame;
		miniGame = nullptr;
	}
}

void MiniGameManager::Set_NewGame()
{
	if (miniGame == nullptr)
	{
		switch ((MiniGameKind)GetRand((int)MiniGameKind::MiniGameKindNum - 1))
		{
		case MiniGameKind::SearchGame:
			miniGame = new SearchGame;
			break;
		case MiniGameKind::BarrageGame:
			miniGame = new Barrage;
			break;
		case MiniGameKind::JustStopGame:
			miniGame = new JustStop;
			break;
		case MiniGameKind::RapidPressGame:
			miniGame = new RapidPress;
			break;
		default:
			break;
		}

	}
}

void MiniGameManager::Delete_Game()
{
	if (miniGame != nullptr)
	{
		delete miniGame;
		miniGame = nullptr;
	}
}

void MiniGameManager::MiniGameInit()
{
	if (miniGame != nullptr)
	{
		miniGame->Init();
	}
}

void MiniGameManager::MiniGameFin()
{
	if (miniGame != nullptr)
	{
		miniGame->Fin();
	}
}