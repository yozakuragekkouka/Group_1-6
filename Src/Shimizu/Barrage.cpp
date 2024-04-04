#include "Barrage.h"
#include "../Nishiyama/Input/Input.h"
#include "../Nishiyama/Shapes/Shapes.h"

const int MAX_COUNT = 60;

void Barrage::Init() {
	StartCount = 3.0f;
	count = MAX_COUNT;
	time = 300.0f;	//5�b
	handle = LoadGraph("Data/Image/");
}

void Barrage::Play() {
	StartCount--;

	if (StartCount <= 0) {
		time--;
	}

	if (Input::IsKeyPush(KEY_INPUT_SPACE)) {//�w��̃L�[��������邽�тɃJ�E���g���}�C�i�X
		count--;
	}


	if (time <= 0.0f || count <= 0) {//�^�C���I�[�o�[ or �J�E���g��0�ŏI��
		isFinish = true;
	}

	/* = GetPoint(count);*/
}

void Barrage::Draw() {
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
	int point;
	if (count == MAX_COUNT) {
		point = 0;
	}
	if (count < MAX_COUNT && count >= 40){
		point = 10;
	}
	if (count < 40 && count >= 30) {
		point = 20;
	}
	if (count < 30 && count >= 20) {
		point = 40;
	}
	if (count < 20 && count >= 10) {
		point = 60;
	}
	if (count < 10 && count >= 0) {
		point = 80;
	}
	if (count <= 0) {
		point = 100;
	}

	return point;
}