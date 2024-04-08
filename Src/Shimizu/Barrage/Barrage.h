#pragma once
#include "../../Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"
#include "../../Nishiyama/Shapes/Shapes.h"

constexpr char BARRAGE_BACK_PATH[128] = "Data/Oda/BackGround/WhiteBG.png";

class Barrage : public MiniGameBase {
private:
	float Startlimit;//開始までのカウントダウン
	int	  count;	 //連打回数
	float time;		 //制限時間
	bool click_flag;
	
	int Buf_Screen;

	Rect_Data back;

public:
	~Barrage();

	void Init();
	void Step();
	void Draw();
	void Fin();

	int GetPoint(int count);
	void CountDown();
	bool IsClick();
};