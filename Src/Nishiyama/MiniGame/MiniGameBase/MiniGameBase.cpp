#include <iostream>
#include "MiniGameBase.h"

MiniGameBase::MiniGameBase()
{
	isClear = false;
	isFinish = false;

	MiniGame_FrameCount = 0;

	strcpy_s(toDo, "デフォルト");
}