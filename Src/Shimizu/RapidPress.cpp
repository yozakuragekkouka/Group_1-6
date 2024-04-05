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
	AppearTiming = ScopingRand(MIN, MAX);
	FlyingStart	 = false;
}

void RapidPress::Play() {
	Startlimit--;
	if (Startlimit <= 0) {
		AppearTime++;
		if (!IsPush) {//指定のキーが押されるまでカウントをプラス

			if (AppearTime >= AppearTiming) {//"!"が出てから処理が始まる
				TimeCount++;
			}

			if (AppearTime < AppearTiming) {//フライングの処理
				if (Input::IsKeyPush(KEY_INPUT_A)) {//キーが押されたらカウントを止める
					FlyingStart = true;
				}
			}

			if (IsKeyPush(KEY_INPUT_A)) {
				IsPush = true;
			}
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
	CountDown();

	if (AppearTime >= AppearTiming) {//"ボタンを押せ"画像

	}

	if (FlyingStart) {//フライング専用画像

	}
}

void RapidPress::Fin() {

}

float RapidPress::GetPoint(float TimeCount) {
	int point = 0;

	if (TimeCount >= 1 && TimeCount < 16) {//0~15フレーム
		point = 100;
	}
	else if (TimeCount >= 16 && TimeCount < 31) {//16~30フレーム
		point = 80;
	}
	else if (TimeCount >= 31 && TimeCount < 46) {//31~45フレーム
		point = 60;
	}
	else if (TimeCount >= 46 && TimeCount < 61) {//46~60フレーム
		point = 40;
	}
	else if (TimeCount >= 61 && TimeCount < 101) {//41~100フレーム
		point = 20;
	}
	else//101以降
		point = 0;

	return point;
}

void RapidPress::CountDown() {
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

float RapidPress::ScopingRand(float min, float max) {
	float rand;

	rand = GetRand(max);

	if (rand <= min) {
		return ScopingRand(min, max);
	}
	else
		return rand;
}