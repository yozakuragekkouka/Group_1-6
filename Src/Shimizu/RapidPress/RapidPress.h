#pragma once
#include "../../Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"
#include "../../Nishiyama/Shapes/Shapes.h"

constexpr char RapidPress_BACK_PATH[128] = "Data/Oda/BackGround/WhiteBG.png";

class RapidPress : public MiniGameBase {
private:
	bool  IsPush;		//�{�^���������ꂽ��
	float Startlimit;	//�Q�[���X�^�[�g�܂ł̎���
	float TimeCount;	//�{�^�����o�Ă���̎���
	float AppearTime;	//�{�^�����o��܂ł̎���
	float AppearTiming;	//"�{�^��������"���o��^�C�~���O
	bool  FlyingStart;	//�t���C���O�������ǂ���

	int Buf_Screen;

	Rect_Data back;
public:
	~RapidPress();

	void Init();
	void Step();
	void Draw();
	void Fin();

	bool GetPoint(float TimeCount);//�������܂ł̎��Ԃ������ɂ��ă|�C���g��ԋp

	void CountDown();

	float ScopingRand(float min, float max);
};