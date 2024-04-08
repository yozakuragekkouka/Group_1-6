#include "SearchGame.h"
#include "../../../../Common.h"
#include "../../../Input/Input.h"

SearchGame::~SearchGame()
{
	back.RectFin();
	light.RectFin();
	bomb.RectFin();
	mushimegane.RectFin();

	DeleteGraph(Buf_Screen);

	if (GetMouseDispFlag() == FALSE)
	{
		SetMouseDispFlag(TRUE);
	}
}

void SearchGame::Init()
{
	if (GetMouseDispFlag() == TRUE)
	{
		SetMouseDispFlag(FALSE);
	}

	isClear = false;
	isFinish = false;

	strcpy_s(toDo, "‚³‚ª‚¹I");

	Buf_Screen = MakeScreen(SCREEN_SIZE_X, SCREEN_SIZE_Y, TRUE);

	back.RectInit(LoadGraph(SEARCH_BACK_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);
	light.RectInit(LoadGraph(LIGHT_PATH), VGet(-100.0f, -100.0f, 0.0f), 128, 128);

	bomb.RectInit(LoadGraph(BOMB_PATH), VGet((float)GetRand(SCREEN_SIZE_X - 200) + 100.0f, (float)GetRand(SCREEN_SIZE_Y - 200) + 100.0f, 0.0f), 64, 64);
	mushimegane.RectInit(LoadGraph(MUSHIMEGANE_PATH), VGet(-100.0f, -100.0f, 0.0f), 128, 128);
}

void SearchGame::Step()
{
	SetDrawScreen(Buf_Screen);
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	light.Set_pos(Input::GetMousePos());
	mushimegane.Set_pos(Input::GetMousePos());

	if (Input::ClickRect(bomb))
	{
		isClear = true;
		isFinish = true;
	}

	MiniGame_FrameCount++;
	if (MiniGame_FrameCount >= MINIGAME_MAXTIME)
	{
		isFinish = true;
	}
}
void SearchGame::Draw()
{
	SetDrawScreen(DX_SCREEN_BACK);

	back.DrawRect();
	bomb.DrawRect();

	SetDrawScreen(Buf_Screen);
	ClearDrawScreen();
	SetDrawBlendMode(DX_BLENDMODE_PMA_INVSRC, 255);
	back.DrawRect();
	SetDrawBlendMode(DX_BLENDMODE_SUB, 255);
	light.DrawRect_Rota_Center();

	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawBlendMode(DX_BLENDMODE_PMA_INVSRC, 255);
	DrawExtendGraph(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, Buf_Screen, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	mushimegane.DrawRect_Rota_Center();

	DrawString(SCREEN_SIZE_X / 2 - 50, 100, toDo, GetColor(0, 0, 0));

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(DX_SCREEN_BACK);
}
void SearchGame::Fin()
{
	back.RectFin();
	light.RectFin();
	bomb.RectFin();
	mushimegane.RectFin();

	DeleteGraph(Buf_Screen);

	if (GetMouseDispFlag() == FALSE)
	{
		SetMouseDispFlag(TRUE);
	}
}