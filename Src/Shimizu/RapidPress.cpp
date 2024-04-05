#include <stdlib.h>

#include "RapidPress.h"
#include "../Nishiyama/Input/Input.h"

const int MIN = 60, MAX = 300;//�ő�1�b,�Œx5�b�ŏo��

#define RANGE ((MAX) - (MIN) + 1)

void RapidPress::Init() {
	IsPush = false;
	Startlimit	 = 210.0f;//�J�n�܂�3�b+START�\���̗P�\(0.5�b)
	TimeCount	 = 0.0f;
	AppearTime	 = 0.0f;
	AppearTiming = ScopingRand(MIN, MAX);
	FlyingStart	 = false;
}

void RapidPress::Play() {
	Startlimit--;
	if (Startlimit <= 0) {
		AppearTime++;
		if (!IsPush) {//�w��̃L�[���������܂ŃJ�E���g���v���X

			if (AppearTime >= AppearTiming) {//"!"���o�Ă��珈�����n�܂�
				TimeCount++;
			}

			if (AppearTime < AppearTiming) {//�t���C���O�̏���
				if (Input::IsKeyPush(KEY_INPUT_A)) {//�L�[�������ꂽ��J�E���g���~�߂�
					FlyingStart = true;
				}
			}

			if (IsKeyPush(KEY_INPUT_A)) {
				IsPush = true;
			}
		}

		if (IsPush) {
			GetPoint(TimeCount); //���

			isFinish = true;
		}

		if (AppearTime > 360.0f) {//6�b�o�����狭���I�ɏI��
			isFinish = true;
		}
	}
}

void RapidPress::Draw() {
	CountDown();

	if (AppearTime >= AppearTiming) {//"�{�^��������"�摜

	}

	if (FlyingStart) {//�t���C���O��p�摜

	}
}

void RapidPress::Fin() {

}

float RapidPress::GetPoint(float TimeCount) {
	int point = 0;

	if (TimeCount >= 1 && TimeCount < 16) {//0~15�t���[��
		point = 100;
	}
	else if (TimeCount >= 16 && TimeCount < 31) {//16~30�t���[��
		point = 80;
	}
	else if (TimeCount >= 31 && TimeCount < 46) {//31~45�t���[��
		point = 60;
	}
	else if (TimeCount >= 46 && TimeCount < 61) {//46~60�t���[��
		point = 40;
	}
	else if (TimeCount >= 61 && TimeCount < 101) {//41~100�t���[��
		point = 20;
	}
	else//101�ȍ~
		point = 0;

	return point;
}

void RapidPress::CountDown() {
	//3,2,1�̃J�E���g�_�E���摜��z��ŏ��Ԃɕ\��
	if (Startlimit <= 210.0f && Startlimit > 150.0f) {	//3
		DrawFormatString(100, 100, GetColor(255, 255, 255), "3");
	}
	if (Startlimit <= 150.0f && Startlimit > 90.0f) {	//2
		DrawFormatString(100, 100, GetColor(255, 255, 255), "2");
	}
	if (Startlimit <= 90.0f && Startlimit > 30.0f) {	//1
		DrawFormatString(100, 100, GetColor(255, 255, 255), "1");
	}
	if (Startlimit <= 30.0f && Startlimit > 0.0f) {		//start
		DrawFormatString(100, 100, GetColor(255, 255, 255), "start");
	}
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