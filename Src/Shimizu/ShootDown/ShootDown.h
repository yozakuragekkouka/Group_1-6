#pragma once
#include "../../Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"

const int TargetMax = 2;

const int Height = 100, Width = 100;

class ShootDown : public MiniGameBase {
private:
	float Startlimit;//�J�n�܂ł̃J�E���g�_�E��
	float time;		 //��������(10�b���炢)
	int	  count;		 //�������Ƃ�����
	int	  handle;
	bool  click_flag;

	int RectX, RectY; //��`�̍��W
	bool IsHit;		  //�������Ă��邩
	float Limit;	  //�\������Ă���N���b�N����܂ł̗P�\

public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	int GetPoint(int count);
	void CountDown();
	bool IsClickOnRect();
	bool RectToMousePointa();//������RectX[i],RectY[i]��n��
	//�����Ə����ݒ肵,�w��͈͂��痐�����擾����֐�
	//����(����,���)
	float ScopingRand(float min, float max);
};