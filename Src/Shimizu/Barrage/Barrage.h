#pragma once
#include "../../Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"
#include "../../Nishiyama/Shapes/Shapes.h"

constexpr char BARRAGE_BACK_PATH[128] = "Data/Oda/BackGround/WhiteBG.png";

class Barrage : public MiniGameBase {
private:
	float Startlimit;//�J�n�܂ł̃J�E���g�_�E��
	int	  count;	 //�A�ŉ�
	float time;		 //��������
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