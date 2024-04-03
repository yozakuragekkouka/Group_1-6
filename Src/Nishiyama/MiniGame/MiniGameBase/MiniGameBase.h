#pragma once
#include "../../FrameRate/FrameRate.h"

constexpr int TODO_SIZE = 128;
constexpr int MINIGAME_MAXTIME = FRAME_RATE * 5;

class MiniGameBase
{
protected:
	bool isClear;
	bool isFinish;

	int MiniGame_FrameCount;

	char toDo[TODO_SIZE];

public:
	virtual void Init() { return; }
	virtual void Step() { return; }
	virtual void Draw() { return; }
	virtual void Fin() { return; }
};