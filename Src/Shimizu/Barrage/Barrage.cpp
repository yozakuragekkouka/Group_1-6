#include "Barrage.h"
#include "../../Common.h"
#include "../../Nishiyama/Input/Input.h"

const int MAX_COUNT = 40;

Barrage::~Barrage()
{
	back.RectFin();

	DeleteGraph(Buf_Screen);

	if (GetMouseDispFlag() == FALSE)
	{
		SetMouseDispFlag(TRUE);
	}
}

void Barrage::Init() {
	if (GetMouseDispFlag() == TRUE)
	{
		SetMouseDispFlag(FALSE);
	}

	Startlimit = 210.0f;//開始まで3秒+START表示の猶予(0.5秒)
	count = MAX_COUNT;
	time = 300.0f;	//5秒
	click_flag = false;

	isClear = false;
	isFinish = false;

	strcpy_s(toDo, "連打しろ！");

	Buf_Screen = MakeScreen(SCREEN_SIZE_X, SCREEN_SIZE_Y, TRUE);

	back.RectInit(LoadGraph(BARRAGE_BACK_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);
}

void Barrage::Step() {
	SetDrawScreen(Buf_Screen);
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	time--;
	if (IsClick()) {//指定のキーが押されるたびにカウントをマイナス
		count--;
	}

	if (count <= 0) {
		isClear = true;
	}

	if (time <= 0.0f || count <= 0) {//タイムオーバー or カウントが0で終了
		isFinish = true;
	}
}

void Barrage::Draw() {
	SetDrawScreen(DX_SCREEN_BACK);

	back.DrawRect();

	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 0, 0), "%d", count);

	DrawString(SCREEN_SIZE_X / 2 - 50, 100, toDo, GetColor(0, 0, 0));

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(DX_SCREEN_BACK);
}

void Barrage::Fin() {
	back.RectFin();

	DeleteGraph(Buf_Screen);

	if (GetMouseDispFlag() == FALSE)
	{
		SetMouseDispFlag(TRUE);
	}
}

bool Barrage::IsClick()
{
	//矩形の中にある
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		//押されている
		if (click_flag == false)
		{
			//押されつづけていない
			click_flag = true;
			return true;
		}
		return false;
	}
	else
	{
		//押されていない
		click_flag = false;
		return false;
	}
}