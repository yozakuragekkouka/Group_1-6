#include "ShootDown.h"
#include "../../Nishiyama/Input/Input.h"

void ShootDown::Init() {
	Startlimit = 210.0f;//�J�n�܂�3�b+START�\���̗P�\(0.5�b)
	time = 600.0f;	//10�b
	count = 0;
	handle = LoadGraph("Data/Image/");
	click_flag = false;
	RectX = ScopingRand(0, 640 - Width);
	RectY = ScopingRand(0, 480 - Height);
	Limit = 0.0f;
	IsHit = false;
}

void ShootDown::Play() {
	Startlimit--;//�X�^�[�g�܂ł̃J�E���g�_�E��

	if (Startlimit <= 0) {
		time--;
		Limit++;
		if (!isFinish) {
			if (IsClickOnRect()) {//�w��̃L�[��������邽�тɃJ�E���g���v���X
				IsHit = true;
				count++;
			}
		}
	}

	if (IsHit || Limit >= 50) {
		RectX = ScopingRand(0, 640 - Width);
		RectY = ScopingRand(0, 480 - Height);

		IsHit = false;
		Limit = 0.0f;
	}


	if (time <= 0.0f) {//�^�C���I�[�o�[�ŏI��
		/*GamePoint = GetPoint(count);*/		//������s��

		isFinish = true;
	}
}

void ShootDown::Draw() {
	CountDown();

	if (Startlimit <= 0 && time >= 0.0f) {
		DrawBox(RectX, RectY, RectX + Width, RectY + Height, GetColor(255, 255, 255), true);
	}
}

void ShootDown::Fin() {
	/*DeleteGraph();*/
}

int ShootDown::GetPoint(int count) {
	int point = 0;

	if (count >= 20) {
		point = 100;
	}
	if (count < 20 && count >= 15) {
		point = 75;
	}
	if (count < 15 && count >= 10) {
		point = 50;
	}
	if (count < 10 && count >= 5) {
		point = 25;
	}
	if (count < 5 && count >= 1) {
		point = 10;
	}
	if (count <= 0) {
		point = 0;
	}

	return point;
}

void ShootDown::CountDown() {
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

bool ShootDown::IsClickOnRect()
{
	//��`�̒��ɂ���

	
		if (RectToMousePointa()) {
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
		else
			return false;
}

bool ShootDown::RectToMousePointa() {
	int x = 0;
	int y = 0;

	GetMousePoint(&x, &y);
	
	for (int i = 0; i < TargetMax; i++) {
		if (RectX + Width >= x && RectX <= x
			&& RectY + Height >= y && RectY <= y) {
			return true;
		}
		else
			return false;
	}
}

float ShootDown::ScopingRand(float min, float max) {
	float rand;

	rand = GetRand(max);

	if (rand <= min) {
		return ScopingRand(min, max);
	}
	else
		return rand;
}

