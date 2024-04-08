#include <stdlib.h>

#include "RapidPress.h"
#include "../../Common.h"
#include "../../Nishiyama/Input/Input.h"

const int MIN = 60, MAX = 300;//�ő�1�b,�Œx5�b�ŏo��

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
	Startlimit	 = 210.0f;//�J�n�܂�3�b+START�\���̗P�\(0.5�b)
	TimeCount	 = 0.0f;
	AppearTime	 = 0.0f;
	AppearTiming = ScopingRand(MIN, MAX);
	FlyingStart	 = false;

	isClear = false;
	isFinish = false;

	strcpy_s(toDo, "�u!�v�Ŏ~�߂�I");

	Buf_Screen = MakeScreen(SCREEN_SIZE_X, SCREEN_SIZE_Y, TRUE);

	back.RectInit(LoadGraph(RapidPress_BACK_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);
}

void RapidPress::Step() {
	SetDrawScreen(Buf_Screen);
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	AppearTime++;
	if (!IsPush) {//�w��̃L�[���������܂ŃJ�E���g���v���X

		if (AppearTime >= AppearTiming) {//"!"���o�Ă��珈�����n�܂�
			TimeCount++;
		}

		if (AppearTime < AppearTiming) {//�t���C���O�̏���
			if ((GetMouseInput() & MOUSE_INPUT_LEFT)) {//�L�[�������ꂽ��J�E���g���~�߂�
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

	

	if (AppearTime > 360.0f) {//6�b�o�����狭���I�ɏI��
		isFinish = true;
	}
}

void RapidPress::Draw() {
	SetDrawScreen(DX_SCREEN_BACK);

	back.DrawRect();

	if (AppearTime >= AppearTiming) {//"�{�^��������"�摜
		DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 0, 0), "!");
	}

	if (FlyingStart) {//�t���C���O��p�摜
		DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(0, 0, 0), "�t���C���O");
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

	if (TimeCount >= 1 && TimeCount < 30) {//0~30�t���[��
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