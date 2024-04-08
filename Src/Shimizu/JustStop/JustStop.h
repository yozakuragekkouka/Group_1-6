#pragma once
#include "../../Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"
#include "../../Nishiyama/Shapes/Shapes.h"

constexpr char JUST_BACK_PATH[128] = "Data/Oda/BackGround/WhiteBG.png";

class JustStop : public MiniGameBase{
protected:
	bool IsPush;//�{�^���������ꂽ��

private:
	float X,Y;		//��`�̍��W
	float LineY;	//�I�����̍��W
	float GetDistance(float rectY, float lineY, float height);	//��`�Ɛ��̋�����Ԃ�(��`��Y���W,����Y���W,��`�̍���)

	int Buf_Screen;

	Rect_Data back;
public:
	~JustStop();

	void Init();
	void Step();
	void Draw();
	void Fin();

	bool GetPoint(float dist);						//��`�Ɛ��̋�������|�C���g���擾(��`�Ɛ��̋���)
};