#include "Barrage.h"
#include "../Nishiyama/Input/Input.h"
#include "../Nishiyama/Shapes/Shapes.h"

const int MAX_COUNT = 40;

void Barrage::Init() {
	Startlimit = 210.0f;//開始まで3秒+START表示の猶予(0.5秒)
	count = MAX_COUNT;
	time = 300.0f;	//5秒
	handle = LoadGraph("Data/Image/");
	click_flag = false;
}

void Barrage::Play() {
	Startlimit--;//スタートまでのカウントダウン

	if (Startlimit <= 0) {
		time--;
		if (!isClear) {
			if (Input::IsKeyPush(KEY_INPUT_SPACE)) {//指定のキーが押されるたびにカウントをマイナス
				count--;
			}
		}
	}


	if (time <= 0.0f || count <= 0) {//タイムオーバー or カウントが0で終了
		isFinish = true;
		/* = GetPoint(count);*/
	}
}

void Barrage::Draw() {
	CountDown();
	switch (GetPoint(count)) {
	case 0:
		//カウントフル
		
		break;
	case 10:
		//残り90%

		break;
	case 20:
		//残り80%

		break;
	case 40:
		//残り60%

		break;
	case 60:
		//残り40%

		break;
	case 80:
		//残り20%

		break;
	case 100:
		//残り0%

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
	//3,2,1のカウントダウン画像を配列で順番に表示
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
	//矩形の中にある
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		//押されている
		if (click_flag == false)
		{
			//押されつづけていない
			click_flag = true;
			return true;
		}
		return false;
	}
	else
	{
		//押されていない
		click_flag = false;
		return false;
	}
}