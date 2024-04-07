#pragma once
#include "Scene.h"
#include "../../Oda/Sound/Sound.h"

#define START_IMG_SIZE_X 400
#define START_IMG_SIZE_Y 66

//oda
class SceneTitle : public SceneBase
{
private:
	// �}�E�X�J�[�\�����W
	int MouseX;
	int MouseY;

	// �摜�n���h��
	int TitleBGHandle;
	int StartHandle;
	int ProvideHandle;

	// State�摜�̍��W
	int StartPosX;
	int StartPosY;

	// �摜�T�C�Y
	float imgSize;

	// �����x�ϐ�
	int Transparency;

	// �傫���ύX����
	bool isChangeSize;

	// �����x����
	bool isTrans;

	// �^�C�g���V�[���̃T�E���h�n���h��
	int TitleSoundHandle[TITLESOUND_MAX_NUM];

public:
	SceneTitle();
	~SceneTitle();

	void Init();

	void Step();

	void Draw();

	void Fin();

	// �}�E�X�ڐG����
	void MouseContact();

	// �傫���ύX����
	void ChangeSize();

	// �����x�ϐ�����
	void TransparencyProcessing();

	// �}�E�X�̓����蔻��̏���
	bool MouseCollision();

	// �^�C�g���V�[���̃t�@�C���ǂݍ���
	void LoadSoundTitle();

	// �^�C�g���V�[���̃t�@�C���j��
	void DeleteSoundTitle();
};
