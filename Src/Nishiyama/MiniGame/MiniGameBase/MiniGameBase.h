#pragma once
#include "../../FrameRate/FrameRate.h"

constexpr int TODO_SIZE = 128;
constexpr int MINIGAME_MAXTIME = FRAME_RATE * 5;

class MiniGameBase
{
protected:
	bool isClear;				//クリア条件を満たしたらこれをtrue
	bool isFinish;				//ゲームが終わったらこれをtrue

	int MiniGame_FrameCount;	//経過フレームをこれでカウント

	char toDo[TODO_SIZE];		//そのゲームで何をするか

public:
	MiniGameBase();

	virtual void Init() { return; }
	virtual void Step() { return; }
	virtual void Draw() { return; }
	virtual void Fin() { return; }

	bool GetisFinish() const { return isFinish; }
	bool GetisClear() const { return isClear; }
};