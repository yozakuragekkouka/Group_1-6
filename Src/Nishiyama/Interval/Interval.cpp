#include "Interval.h"
#include "../Score/ScoreManager/ScoreManager.h"

void Interval::Init()
{
	state = IntervalState::Stay_MiniGame;
	intervalFrameCount = 0;
	All_Fin = false;

	BG_Image.RectInit(LoadGraph(INTERVAL_BG_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);
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
		BG_Image.Set_posY(BG_Image.Get_posY() - 6.0f);

		intervalFrameCount++;
		if (intervalFrameCount >= MINIGAME_START_FRAME)
		{
			BG_Image.Set_posY(-720.0f);

			intervalFrameCount = 0;
			state = IntervalState::Playing_MiniGame;
		}
		break;
	case IntervalState::Playing_MiniGame:
		break;
	case IntervalState::End_MiniGame:
		BG_Image.Set_posY(BG_Image.Get_posY() + 6.0f);

		intervalFrameCount++;
		if (intervalFrameCount >= MINIGAME_END_FRAME)
		{
			BG_Image.Set_posY(0.0f);

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
	BG_Image.DrawRect();
}

void Interval::Fin()
{
	BG_Image.RectFin();
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