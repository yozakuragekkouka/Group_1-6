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
	AppearTiming = (MIN + rand() % RANGE);
	FlyingStart	 = false;
}

void RapidPress::Play() {
	Startlimit--;
	if (Startlimit <= 0) {
		AppearTime++;
		if (AppearTime >= AppearTiming) {//"����"���o�Ă��珈�����n�܂�
			if (!IsPush) {//�w��̃L�[���������܂ŃJ�E���g���v���X
				TimeCount++;
			}
		}

		if (Input::IsKeyPush(KEY_INPUT_A)) {//�L�[�������ꂽ��J�E���g���~�߂�
			if (AppearTime < AppearTiming) {//�t���C���O�̏���
				TimeCount = -1;
				isFinish = true;
				FlyingStart = true;
				GetPoint(TimeCount); //���
			}
			else
				IsPush = true;
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
	//3,2,1�̃J�E���g�_�E���摜��z��ŏ��Ԃɕ\��
	if(Startlimit <= 210.0f && Startlimit > 150.0f){	//3

	}
	if (Startlimit <= 150.0f && Startlimit > 90.0f) {	//2

	}
	if (Startlimit <= 90.0f && Startlimit > 30.0f) {	//1

	}
	if (Startlimit <= 30.0f && Startlimit > 0.0f) {		//start

	}

	if (FlyingStart) {//�t���C���O��p�摜

	}
}

void RapidPress::Fin() {

}

float RapidPress::GetPoint(float TimeCount) {
	int point = 0;

	if (TimeCount == -1) {
		point = 0;
	}

	if (TimeCount >= 0 && TimeCount < 21) {//0~20�t���[��
		point = 100;
	}
	else if (TimeCount >= 21 && TimeCount < 41) {//21~40�t���[��
		point = 80;
	}
	else if (TimeCount >= 41 && TimeCount < 61) {//41~60�t���[��
		point = 60;
	}
	else if (TimeCount >= 61 && TimeCount < 81) {//61~80�t���[��
		point = 40;
	}
	else if (TimeCount >= 81 && TimeCount < 101) {//81~100�t���[��
		point = 20;
	}
	else//101�ȍ~
		point = 0;
	
	return point;
}