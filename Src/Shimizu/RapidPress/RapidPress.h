#pragma once
#include "../../Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"

class RapidPress : public MiniGameBase {
private:
	bool  IsPush;		//ボタンが押されたか
	float Startlimit;	//ゲームスタートまでの時間
	float TimeCount;	//ボタンが出てからの時間
	float AppearTime;	//ボタンが出るまでの時間
	float AppearTiming;	//"ボタンを押せ"が出るタイミング
	bool  FlyingStart;	//フライングしたかどうか
public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	float GetPoint(float TimeCount);//押されるまでの時間を引数にしてポイントを返却

	void CountDown();

	float ScopingRand(float min, float max);
};