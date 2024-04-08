#pragma once
#include "../../Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"
#include "../../Nishiyama/Shapes/Shapes.h"

constexpr char RapidPress_BACK_PATH[128] = "Data/Oda/BackGround/WhiteBG.png";

class RapidPress : public MiniGameBase {
private:
	bool  IsPush;		//ボタンが押されたか
	float Startlimit;	//ゲームスタートまでの時間
	float TimeCount;	//ボタンが出てからの時間
	float AppearTime;	//ボタンが出るまでの時間
	float AppearTiming;	//"ボタンを押せ"が出るタイミング
	bool  FlyingStart;	//フライングしたかどうか

	int Buf_Screen;

	Rect_Data back;
public:
	~RapidPress();

	void Init();
	void Step();
	void Draw();
	void Fin();

	bool GetPoint(float TimeCount);//押されるまでの時間を引数にしてポイントを返却

	void CountDown();

	float ScopingRand(float min, float max);
};