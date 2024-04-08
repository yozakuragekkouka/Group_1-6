#include "MiniGameManager.h"
#include "../MiniGame_shuu/SearchGame/SearchGame.h"

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