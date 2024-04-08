#pragma once
#include "../../Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"

class Barrage : public MiniGameBase {
private:
	float Startlimit;//開始までのカウントダウン
	int	  count;	 //連打回数
	float time;		 //制限時間
	int	  handle;
	bool click_flag;
	
public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	int GetPoint(int count);
	void CountDown();
	bool IsClick();
};