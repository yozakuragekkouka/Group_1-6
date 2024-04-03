#pragma once
#include "../MiniGameBase/MiniGameBase.h"
#include "../../GameState/GameState.h"

class MiniGameManager
{
private:
	MiniGameBase* miniGame;

public:
	void Init() { return; }
	int Step() { return 0; }
	void Draw() { return; }
	void Fin() { return; }
};