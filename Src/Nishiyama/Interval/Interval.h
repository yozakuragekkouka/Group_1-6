#pragma once
#include "../GameState/GameState.h"

class Interval
{
private:
	bool isStart_MiniGame;


public:
	void Init() { isStart_MiniGame = false; }
	bool Step(int StepKind) { return; }
	void Draw() { return; }
	void Fin() { return; }
};