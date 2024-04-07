#pragma once
#include "../../Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"

const int TargetMax = 2;

const int Height = 100, Width = 100;

class ShootDown : public MiniGameBase {
private:
	float Startlimit;//開始までのカウントダウン
	float time;		 //制限時間(10秒くらい)
	int	  count;		 //撃ち落とした回数
	int	  handle;
	bool  click_flag;

	int RectX, RectY; //矩形の座標
	bool IsHit;		  //当たっているか
	float Limit;	  //表示されてからクリックするまでの猶予

public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	int GetPoint(int count);
	void CountDown();
	bool IsClickOnRect();
	bool RectToMousePointa();//引数でRectX[i],RectY[i]を渡す
	//下限と上限を設定し,指定範囲から乱数を取得する関数
	//引数(下限,上限)
	float ScopingRand(float min, float max);
};