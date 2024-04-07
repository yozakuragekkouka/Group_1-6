#include "ShootDown.h"
#include "../../Nishiyama/Input/Input.h"

void ShootDown::Init() {
	Startlimit = 210.0f;//開始まで3秒+START表示の猶予(0.5秒)
	time = 600.0f;	//10秒
	count = 0;
	handle = LoadGraph("Data/Image/");
	click_flag = false;
	RectX = ScopingRand(0, 640 - Width);
	RectY = ScopingRand(0, 480 - Height);
	Limit = 0.0f;
	IsHit = false;
}

void ShootDown::Play() {
	Startlimit--;//スタートまでのカウントダウン

	if (Startlimit <= 0) {
		time--;
		Limit++;
		if (!isFinish) {
			if (IsClickOnRect()) {//指定のキーが押されるたびにカウントをプラス
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


	if (time <= 0.0f) {//タイムオーバーで終了
		/*GamePoint = GetPoint(count);*/		//代入を行う

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

bool ShootDown::IsClickOnRect()
{
	//矩形の中にある

	
		if (RectToMousePointa()) {
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

