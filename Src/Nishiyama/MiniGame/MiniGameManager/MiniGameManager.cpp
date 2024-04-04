#include "MiniGameManager.h"

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
	}
}

void MiniGameManager::Set_NewGame()
{
	if (miniGame == nullptr)
	{

	}
}

void MiniGameManager::Delete_Game()
{
	if (miniGame != nullptr)
	{
		delete miniGame;
	}
}