#include <stdlib.h>

#include "RapidPress.h"
#include "../../Common.h"
#include "../../Nishiyama/Input/Input.h"

const int MIN = 60, MAX = 300;//最速1秒,最遅5秒で出現

#define RANGE ((MAX) - (MIN) + 1)

RapidPress::~RapidPress()
{
	back.RectFin();

	DeleteGraph(Buf_Screen);

	if (GetMouseDispFlag() == FALSE)
	{
		SetMouseDispFlag(TRUE);
	}
}

void RapidPress::Init() {
	if (GetMouseDispFlag() == TRUE)
	{
		SetMouseDispFlag(FALSE);
	}

	IsPush = false;
	Startlimit	 = 210.0f;//開始まで3秒+START表示の猶予(0.5秒)
	TimeCount	 = 0.0f;
	AppearTime	 = 0.0f;
	AppearTiming = ScopingRand(MIN, MAX);
	FlyingStart	 = false;

	isClear = false;
	isFinish = false;

	strcpy_s(toDo, "「!」で止めろ！");

	Buf_Screen = MakeScreen(SCREEN_SIZE_X, SCREEN_SIZE_Y, TRUE);

	back.RectInit(LoadGraph(RapidPress_BACK_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);
}

void RapidPress::Step() {
	SetDrawScreen(Buf_Screen);
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	AppearTime++;
	if (!IsPush) {//指定のキーが押されるまでカウントをプラス

		if (AppearTime >= AppearTiming) {//"!"が出てから処理が始まる
			TimeCount++;
		}

		if (AppearTime < AppearTiming) {//フライングの処理
			if ((GetMouseInput() & MOUSE_INPUT_LEFT)) {//キーが押されたらカウントを止める
				FlyingStart = true;
			}
		}

		if ((GetMouseInput() & MOUSE_INPUT_LEFT)) {
			IsPush = true;
		}
	}

	if (IsPush) {
		if (GetPoint(TimeCount)) {
			isClear = true;
		}
		isFinish = true;
	}

	

	if (AppearTime > 360.0f) {//6秒経ったら強制的に終了
		isFinish = true;
	}
}

void RapidPress::Draw() {
	SetDrawScreen(DX_SCREEN_BACK);

	back.DrawRect();

	if (AppearTime >= AppearTiming) {//"ボタンを押せ"画像
		DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 0, 0), "!");
	}

	if (FlyingStart) {//フライング専用画像
		DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 0, 0), "フライング");
	}

	DrawString(SCREEN_SIZE_X / 2 - 50, 100, toDo, GetColor(0, 0, 0));

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawScreen(DX_SCREEN_BACK);
}

void RapidPress::Fin() {
	back.RectFin();

	DeleteGraph(Buf_Screen);

	if (GetMouseDispFlag() == FALSE)
	{
		SetMouseDispFlag(TRUE);
	}
}

bool RapidPress::GetPoint(float TimeCount) {

	if (TimeCount >= 1 && TimeCount < 30) {//0~30フレーム
		return true;
	}

	return false;
}

float RapidPress::ScopingRand(float min, float max) {
	float rand;

	rand = GetRand(max);

	if (rand <= min) {
		return ScopingRand(min, max);
	}
	else
		return rand;
}