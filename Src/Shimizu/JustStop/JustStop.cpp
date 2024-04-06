#include "JustStop.h"
#include "../Nishiyama/Input/Input.h"
#include "../Nishiyama/Shapes/Shapes.h"

#define LINEY 400.0f
#define HEIGHT 20

void JustStop::Init() {
	handle = LoadGraph("Data/Image/");
	IsPush = false;
	X = 0.0f;
	Y = 0.0f;
	LineY = LINEY;
	Startlimit = 210.0f;
}

void JustStop::Play() {
	Startlimit--;
	if (Startlimit <= 0) {
		//�{�^���������ꂽ�牺�~���X�g�b�v
		if ((GetMouseInput() & MOUSE_INPUT_LEFT)) {
			IsPush = true;
		}

		//IsPush���������܂ŉ��~����
		if (!IsPush) {
			Y += 5;
		}
		else//���~���~�܂�ΏI��
			isFinish = true;

		if (GetDistance(Y, LineY, HEIGHT) < 0) {//��`�������z������I��
			isFinish = true;
		}

		if (isFinish) {//�Q�[�����I��������|�C���g���擾����
			GetPoint(GetDistance(Y, LineY, HEIGHT));//���
		}
	}
}

void JustStop::Draw() {
	CountDown();

	if (!(GetDistance(Y, LineY,HEIGHT) < 0)) {//��`�������z���Ă��Ȃ����
		DrawGraph(X, Y, handle, true);
	}
}

void JustStop::Fin() {
	DeleteGraph(handle);
}

float JustStop::GetDistance(float rectY, float lineY, float height) {
	return lineY - (height + rectY);
}

float JustStop::GetPoint(float dist) {
	int point = 0;
	float i = LINEY / 100.0f;

	if (dist >= 0 && dist < 5 * i) {
		point = 100;
	}
	if (dist >= 5 && dist < 20 * i) {
		point = 80;
	}
	if (dist >= 20 * i && dist < 40 * i) {
		point = 60;
	}
	if (dist >= 40 * i && dist < 60 * i) {
		point = 40;
	}
	if (dist >= 60 * i && dist < 80 * i) {
		point = 20;
	}
	if (dist >= 80 * i && dist <= 100 * i) {
		point = 10;
	}
	if (dist < 0) {
		point = 0;
	}

	return point;
}

void JustStop::CountDown() {
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
