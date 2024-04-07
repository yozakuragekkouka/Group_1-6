#include "Barrage.h"
#include "../Nishiyama/Input/Input.h"
#include "../Nishiyama/Shapes/Shapes.h"

const int MAX_COUNT = 40;

void Barrage::Init() {
	Startlimit = 210.0f;//�J�n�܂�3�b+START�\���̗P�\(0.5�b)
	count = MAX_COUNT;
	time = 300.0f;	//5�b
	handle = LoadGraph("Data/Image/");
	click_flag = false;
}

void Barrage::Play() {
	Startlimit--;//�X�^�[�g�܂ł̃J�E���g�_�E��

	if (Startlimit <= 0) {
		time--;
		if (!isClear) {
			if (Input::IsKeyPush(KEY_INPUT_SPACE)) {//�w��̃L�[��������邽�тɃJ�E���g���}�C�i�X
				count--;
			}
		}
	}


	if (time <= 0.0f || count <= 0) {//�^�C���I�[�o�[ or �J�E���g��0�ŏI��
		isFinish = true;
		/* = GetPoint(count);*/
	}
}

void Barrage::Draw() {
	CountDown();
	switch (GetPoint(count)) {
	case 0:
		//�J�E���g�t��
		
		break;
	case 10:
		//�c��90%

		break;
	case 20:
		//�c��80%

		break;
	case 40:
		//�c��60%

		break;
	case 60:
		//�c��40%

		break;
	case 80:
		//�c��20%

		break;
	case 100:
		//�c��0%

		break;
	}
}

void Barrage::Fin() {
	/*DeleteGraph();*/
}

int Barrage::GetPoint(int count) {
	int point = 0;
	if (count == MAX_COUNT) {
		point = 0;
	}
	if (count < MAX_COUNT && count >= MAX_COUNT - 10) {
		point = 20;
	}
	if (count < MAX_COUNT - 10 && count >= MAX_COUNT - 20) {
		point = 40;
	}
	if (count < MAX_COUNT - 20 && count >= MAX_COUNT - 30) {
		point = 60;
	}
	if (count < MAX_COUNT - 30 && count > MAX_COUNT - 40) {
		point = 80;
	}
	if (count <= 0) {
		point = 100;
	}

	return point;
}

void Barrage::CountDown() {
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

bool Barrage::IsClick()
{
	//��`�̒��ɂ���
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		//������Ă���
		if (click_flag == false)
		{
			//������Â��Ă��Ȃ�
			click_flag = true;
			return true;
		}
		return false;
	}
	else
	{
		//������Ă��Ȃ�
		click_flag = false;
		return false;
	}
}