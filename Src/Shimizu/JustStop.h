#pragma once
#include "../../Src/Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"

class JustStop : public MiniGameBase{
protected:
	bool IsPush;//�{�^���������ꂽ��
	int handle;

private:
	float X,Y;		//��`�̍��W
	float LineY;	//�I�����̍��W
	float Startlimit;
	float GetDistance(float rectY, float lineY, float height);	//��`�Ɛ��̋�����Ԃ�(��`��Y���W,����Y���W,��`�̍���)
public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	float GetPoint(float dist);						//��`�Ɛ��̋�������|�C���g���擾(��`�Ɛ��̋���)

	void CountDown();
};