#pragma once
#include "../../Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"

class RapidPress : public MiniGameBase {
private:
	bool  IsPush;		//�{�^���������ꂽ��
	float Startlimit;	//�Q�[���X�^�[�g�܂ł̎���
	float TimeCount;	//�{�^�����o�Ă���̎���
	float AppearTime;	//�{�^�����o��܂ł̎���
	float AppearTiming;	//"�{�^��������"���o��^�C�~���O
	bool  FlyingStart;	//�t���C���O�������ǂ���
public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	float GetPoint(float TimeCount);//�������܂ł̎��Ԃ������ɂ��ă|�C���g��ԋp

	void CountDown();

	float ScopingRand(float min, float max);
};