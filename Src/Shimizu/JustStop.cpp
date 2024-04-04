#include "JustStop.h"
#include "../Nishiyama/Input/Input.h"
#include "../Nishiyama/Shapes/Shapes.h"

#define LINEY 400.0f

void MiniGame::Init() {
	handle = LoadGraph("Data/Image/");
	IsPush = false;
	X = 0.0f;
	Y = 0.0f;
	LineY = LINEY;
}

void MiniGame::Play() {
	//ボタンが押されたら下降をストップ
	if (Input::IsKeyPush(KEY_INPUT_A)) {
		IsPush = true;
	}

	//IsPushが押されるまで下降する
	if (!IsPush) {
		Y++;
	}
	else//下降が止まれば終了
		isFinish = true;

	if (GetDistance(Y, LineY) < 0) {//矩形が線を越えたら終了
		isFinish = true;
	}

	if (isFinish) {//ゲームが終了したらポイントを取得する
		GetPoint(GetDistance(Y, LineY));
	}
}

void MiniGame::Draw() {
	if (!(GetDistance(Y, LineY) < 0)) {//矩形が線を越えていなければ
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
	int point = 0;
	float i = LINEY / 100.0f;

	if (dist == 0) {
		point = 100;
	}
	if (dist >= 0 && dist < 20 * i) {
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
