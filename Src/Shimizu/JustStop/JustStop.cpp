#include "JustStop.h"
#include "../../Common.h"
#include "../../Nishiyama/Input/Input.h"

#define LINEY 620.0f
#define HEIGHT 50

JustStop::~JustStop()
{
	back.RectFin();

	DeleteGraph(Buf_Screen);

	if (GetMouseDispFlag() == FALSE)
	{
		SetMouseDispFlag(TRUE);
	}
}

void JustStop::Init() {
	if (GetMouseDispFlag() == TRUE)
	{
		SetMouseDispFlag(FALSE);
	}

	IsPush = false;
	X = SCREEN_SIZE_X / 2 - 45;
	Y = 120.0f;
	LineY = LINEY;

	isClear = false;
	isFinish = false;

	strcpy_s(toDo, "丁度で止めろ！");

	Buf_Screen = MakeScreen(SCREEN_SIZE_X, SCREEN_SIZE_Y, TRUE);

	back.RectInit(LoadGraph(JUST_BACK_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);
}

void JustStop::Step() {
	SetDrawScreen(Buf_Screen);
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	//ボタンが押されたら下降をストップ
	if ((GetMouseInput() & MOUSE_INPUT_LEFT)) {
		IsPush = true;
		isFinish = true;
	}

	if (IsPush) {
		if (GetPoint(GetDistance(Y, LineY, HEIGHT))) {
			isClear = true;
		}
	}

	//IsPushが押されるまで下降する
	if (!IsPush) {
		Y += 5;
	}

	if (GetDistance(Y, LineY, HEIGHT) < 0) {//矩形が線を越えたら終了
		isFinish = true;
	}

	MiniGame_FrameCount++;
	if (MiniGame_FrameCount >= MINIGAME_MAXTIME)
	{
		isFinish = true;
	}
}

void JustStop::Draw() {

	SetDrawScreen(DX_SCREEN_BACK);

	back.DrawRect();

	DrawLine(0, LINEY, SCREEN_SIZE_X, LINEY, GetColor(0, 0, 0));

	if (!(GetDistance(Y, LineY,HEIGHT) < 0)) {//矩形が線を越えていなければ
		DrawBox(X, Y, X + 50, Y + HEIGHT, GetColor(0, 0, 0), true);
	}

	DrawString(SCREEN_SIZE_X / 2 - 50, 100, toDo, GetColor(0, 0, 0));

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(DX_SCREEN_BACK);
}

void JustStop::Fin() {
	back.RectFin();
	
	DeleteGraph(Buf_Screen);

	if (GetMouseDispFlag() == FALSE)
	{
		SetMouseDispFlag(TRUE);
	}
}

float JustStop::GetDistance(float rectY, float lineY, float height) {
	return lineY - (height + rectY);
}

bool JustStop::GetPoint(float dist) {
	int point = 0;

	if (dist >= 0 && dist < 20) {
		return true;
	}

	return false;
}

