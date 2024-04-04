#include <stdlib.h>

#include "RapidPress.h"
#include "../Nishiyama/Input/Input.h"

const int MIN = 60, MAX = 300;//最速1秒,最遅5秒で出現

#define RANGE ((MAX) - (MIN) + 1)

void RapidPress::Init() {
	IsPush = false;
	Startlimit	 = 210.0f;//開始まで3秒+START表示の猶予(0.5秒)
	TimeCount	 = 0.0f;
	AppearTime	 = 0.0f;
	AppearTiming = (MIN + rand() % RANGE);
	FlyingStart	 = false;
}

void RapidPress::Play() {
	Startlimit--;
	if (Startlimit <= 0) {
		AppearTime++;
		if (AppearTime >= AppearTiming) {//"押せ"が出てから処理が始まる
			if (!IsPush) {//指定のキーが押されるまでカウントをプラス
				TimeCount++;
			}
		}

		if (Input::IsKeyPush(KEY_INPUT_A)) {//キーが押されたらカウントを止める
			if (AppearTime < AppearTiming) {//フライングの処理
				TimeCount = -1;
				isFinish = true;
				FlyingStart = true;
				GetPoint(TimeCount); //代入
			}
			else
				IsPush = true;
		}
		

		if (IsPush) {
			GetPoint(TimeCount); //代入

			isFinish = true;
		}

		if (AppearTime > 360.0f) {//6秒経ったら強制的に終了
			isFinish = true;
		}
	}
}

void RapidPress::Draw() {
	//3,2,1のカウントダウン画像を配列で順番に表示
	if(Startlimit <= 210.0f && Startlimit > 150.0f){	//3

	}
	if (Startlimit <= 150.0f && Startlimit > 90.0f) {	//2

	}
	if (Startlimit <= 90.0f && Startlimit > 30.0f) {	//1

	}
	if (Startlimit <= 30.0f && Startlimit > 0.0f) {		//start

	}

	if (FlyingStart) {//フライング専用画像

	}
}

void RapidPress::Fin() {

}

float RapidPress::GetPoint(float TimeCount) {
	int point = 0;

	if (TimeCount == -1) {
		point = 0;
	}

	if (TimeCount >= 0 && TimeCount < 21) {//0~20フレーム
		point = 100;
	}
	else if (TimeCount >= 21 && TimeCount < 41) {//21~40フレーム
		point = 80;
	}
	else if (TimeCount >= 41 && TimeCount < 61) {//41~60フレーム
		point = 60;
	}
	else if (TimeCount >= 61 && TimeCount < 81) {//61~80フレーム
		point = 40;
	}
	else if (TimeCount >= 81 && TimeCount < 101) {//81~100フレーム
		point = 20;
	}
	else//101以降
		point = 0;
	
	return point;
}