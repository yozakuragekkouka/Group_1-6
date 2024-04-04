#include "Interval.h"

void Interval::Init()
{
	state = IntervalState::Stay_MiniGame;
	intervalFrameCount = 0;
	All_Fin = false;
}

void Interval::Step()
{
	switch (state)
	{
	case IntervalState::Stay_MiniGame:
		intervalFrameCount++;
		if (intervalFrameCount >= MINIGAME_STAY_FRAME)
		{
			intervalFrameCount = 0;
			state = IntervalState::Start_MiniGame;
		}
		break;
	case IntervalState::Start_MiniGame:
		intervalFrameCount++;
		if (intervalFrameCount >= MINIGAME_START_FRAME)
		{
			intervalFrameCount = 0;
			state = IntervalState::Playing_MiniGame;
		}
		break;
	case IntervalState::Playing_MiniGame:
		break;
	case IntervalState::End_MiniGame:
		intervalFrameCount++;
		if (intervalFrameCount >= MINIGAME_END_FRAME)
		{
			intervalFrameCount = 0;
			state = IntervalState::Stay_MiniGame;
		}
		break;
	default:
		break;
	}
}

void Interval::Draw()
{

}

void Interval::Fin()
{

}

void Interval::End_Step()
{

	intervalFrameCount++;
	if (intervalFrameCount >= MINIGAME_END_STEP_FRAME)
	{
		intervalFrameCount = 0;
		state = IntervalState::Stay_MiniGame;
	}
}