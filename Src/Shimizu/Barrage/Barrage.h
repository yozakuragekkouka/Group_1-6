#pragma once
#include "../../Src/Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"

class Barrage : public MiniGameBase {
private:
	float Startlimit;//�J�n�܂ł̃J�E���g�_�E��
	int	  count;	 //�A�ŉ�
	float time;		 //��������
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