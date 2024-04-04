#pragma once
#include "../../FrameRate/FrameRate.h"

constexpr int TODO_SIZE = 128;
constexpr int MINIGAME_MAXTIME = FRAME_RATE * 5;

class MiniGameBase
{
protected:
	bool isClear;				//�N���A�����𖞂������炱���true
	bool isFinish;				//�Q�[�����I������炱���true

	int MiniGame_FrameCount;	//�o�߃t���[��������ŃJ�E���g

	char toDo[TODO_SIZE];		//���̃Q�[���ŉ������邩

public:
	MiniGameBase();

	virtual void Init() { return; }
	virtual void Step() { return; }
	virtual void Draw() { return; }
	virtual void Fin() { return; }

	bool GetisFinish() const { return isFinish; }
	bool GetisClear() const { return isClear; }
};