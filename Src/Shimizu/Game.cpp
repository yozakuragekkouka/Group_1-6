#include "Game.h"
#include "../Nishiyama/Input/Input.h"
#include "../Nishiyama/Shapes/Shapes.h"

void MiniGame::Init() {
	handle = LoadGraph("Data/Image/");
	IsPush = false;
	X = 0.0f;
	Y = 0.0f;
	LineY = 0.0f;
}

void MiniGame::Play() {
	//�{�^���������ꂽ�牺�~���X�g�b�v
	if (Input::IsKeyPush(KEY_INPUT_A)) {
		IsPush = true;
	}

	//IsPush���������܂ŉ��~����
	if (!IsPush) {
		Y++;
	}
	else//���~���~�܂�ΏI��
		isFinish = true;

	if (GetDistance(Y, LineY) < 0) {//��`�������z������I��
		isFinish = true;
	}

	if (isFinish) {//�Q�[�����I��������|�C���g���擾����
		GetPoint(GetDistance(Y, LineY));
	}
}

void MiniGame::Draw() {
	if (!(GetDistance(Y, LineY) < 0)) {//��`�������z���Ă��Ȃ����
		DrawGraph(X, Y, handle, true);
	}
}

void MiniGame::Fin() {
	DeleteGraph(handle);
}

float MiniGame::GetDistance(float rectY, float lineY) {
	return lineY - rectY;
}

float MiniGame::GetPoint(float dist) {
	int point;

	if (dist == 0) {
		point = 100;
	}
	
	if (dist < 0) {
		point = 0;
	}

	return point;
}
