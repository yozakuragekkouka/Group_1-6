#pragma once
#include "../../Src/Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"

class MiniGame : public MiniGameBase{
protected:
	bool IsPush;//�{�^���������ꂽ��
	int handle;

private:
	float X,Y;		//��`�̍��W
	float LineY;	//�I�����̍��W
	float GetDistance(float rectY, float lineY);	//��`�Ɛ��̋�����Ԃ�(��`��Y���W,����Y���W)
public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	float GetPoint(float dist);						//��`�Ɛ��̋�������|�C���g���擾(��`�Ɛ��̋���)
};