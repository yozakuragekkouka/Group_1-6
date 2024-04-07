#include "DxLib.h"
#include "../../Common.h"
#include "SceneTitle.h"
#include "Scene.h"
#include "../Input/Input.h"
#include "../../Oda/Collision/Collision.h"

//oda
SceneTitle::SceneTitle()
{
	// �}�E�X�J�[�\�����W
	MouseX = 0;
	MouseY = 0;

	// �摜�n���h��
	TitleBGHandle = 0;
	StartHandle = 0;
	ProvideHandle = 0;

	// State�摜�̍��W
	StartPosX = 0;
	StartPosY = 0;

	// �摜�T�C�Y
	imgSize = 0;

	// �����x�ϐ�
	Transparency = 0;

	// �傫���ύX����
	isChangeSize = 0;

	// �����x����
	isTrans = 0;

	// �T�E���h�n���h��
	for (int SoundIndex = 0; SoundIndex < TITLESOUND_MAX_NUM; SoundIndex++)
	{
		TitleSoundHandle[SoundIndex] = 0;
	}
}
SceneTitle::~SceneTitle(){}

//�^�C�g��������
void SceneTitle::Init()
{
	// �摜�n���h��
	TitleBGHandle = LoadGraph("Data/Oda/BackGround/Title.png");
	StartHandle = LoadGraph("Data/Oda/Title/Start.png");
	ProvideHandle = LoadGraph("Data/Oda/Title/MusMus.png");

	// State�摜�̍��W
	StartPosX = SCREEN_SIZE_X / 2;
	StartPosY = SCREEN_SIZE_Y - SCREEN_SIZE_Y / 4;

	// �摜�T�C�Y
	imgSize = 1.0f;

	// �����x�ϐ�
	Transparency = 256;

	// �傫���ύX����
	isChangeSize = false;

	// �����x����
	isTrans = false;

	// �T�E���h�n���h��
	for (int SoundIndex = 0; SoundIndex < TITLESOUND_MAX_NUM; SoundIndex++)
	{
		TitleSoundHandle[SoundIndex] = 0;
	}

	// �t�@�C���ǂݍ���
	LoadSoundTitle();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_TITLE;
}

//�^�C�g���ʏ폈��
void SceneTitle::Step()
{
	// �}�E�X�ڐG����
	MouseContact();

	// �傫���ύX����
	ChangeSize();

	// �����x�ϐ�����
	TransparencyProcessing();
}

//�^�C�g���`�揈��
void SceneTitle::Draw()
{
	// �^�C�g���摜�\��
	DrawGraph(0, 0, TitleBGHandle, true);

	// Stare�{�^���摜�\��
	// �����x���ς��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Transparency);
	DrawRotaGraph(StartPosX, StartPosY, imgSize, 0.0f, StartHandle, false, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// �񋟉摜�\��
	DrawGraph(0, SCREEN_SIZE_Y - 55, ProvideHandle, true);

	// Debug�p
	/*
	DrawFormatString(0, 0, GetColor(255, 0, 0), "%d", MouseX);
	DrawFormatString(0, 25, GetColor(255, 0, 0), "%d", MouseY);
	DrawBox(StartPosX - 175, StartPosY - 30, StartPosX - 175 + START_IMG_SIZE_X - 50, StartPosY - 30 + START_IMG_SIZE_Y - 6, GetColor(255, 0, 0), TRUE);
	*/
}

//�^�C�g���㏈��
void SceneTitle::Fin()
{
	// �}�E�X�J�[�\�����W
	MouseX = 0;
	MouseY = 0;

	// �摜�n���h��
	TitleBGHandle = 0;
	StartHandle = 0;
	ProvideHandle = 0;

	// State�摜�̍��W
	StartPosX = 0;
	StartPosY = 0;

	// �摜�T�C�Y
	imgSize = 0;

	// �����x�ϐ�
	Transparency = 0;

	// �傫���ύX����
	isChangeSize = 0;

	// �����x����
	isTrans = 0;

	// �t�@�C���j��
	DeleteSoundTitle();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_PLAY;
}

// �}�E�X�ڐG����
void SceneTitle::MouseContact()
{
	// �}�E�X�J�[�\�����W���擾
	GetMousePoint(&MouseX, &MouseY);

	// �}�E�X���ڐG���Ă�����
	if (MouseCollision() == true)
	{
		isChangeSize = true;
		isTrans = true;

		// ���N���b�N��������Ă���ꍇ
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			PlaySoundMem(TitleSoundHandle[TITLE_SERECT_SE], DX_PLAYTYPE_BACK, true);
			Sleep(250);
			SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_TITLE;
		}
	}
	// �}�E�X���ڐG���Ă��Ȃ�������
	else
	{
		isChangeSize = false;
		isTrans = false;
	}
}

// �傫���ύX����
void SceneTitle::ChangeSize()
{
	// �傫���ύX���肪�^�Ȃ�
	if (isChangeSize == true) {
		// �摜�T�C�Y��1.0�ɂ���
		imgSize = 1.0f;
	}

	// �傫���ύX���肪�U�Ȃ�
	if (isChangeSize == false) {
		// �摜�T�C�Y��0.8�ɂ���
		imgSize = 0.9f;
	}
}

// �����x�ϐ�����
void SceneTitle::TransparencyProcessing()
{
	// �����x���肪�^�Ȃ�
	if (isTrans == true) {
		// �����x�ϐ���256�ɂ���
		Transparency = 256;
	}

	// �����x���肪�U�Ȃ�
	if (isTrans == false) {
		// �����x�ϐ���128�ɂ���
		Transparency = 160;
	}
}

// �}�E�X�̓����蔻��̏���
bool SceneTitle::MouseCollision()
{
	// State�摜�ƃ}�E�X�J�[�\�����������Ă��邩
	if (Collision::Rect_Dot(StartPosX - START_IMG_SIZE_X / 2 - 25, StartPosY - START_IMG_SIZE_Y / 2 - 6,
							START_IMG_SIZE_X - 50, START_IMG_SIZE_Y - 6,
							MouseX, MouseY))
	{
		return true;
	}

	return false;
}

// �^�C�g���V�[���̃t�@�C���ǂݍ���
void SceneTitle::LoadSoundTitle()
{
	// BGM�̓ǂݍ���
	TitleSoundHandle[TITLE_BGM] = LoadSoundMem(TITLE_BGM_PATH);
	// BGM���Đ�
	PlaySoundMem(TitleSoundHandle[TITLE_BGM], DX_PLAYTYPE_LOOP, true);

	TitleSoundHandle[TITLE_SERECT_SE] = LoadSoundMem(SELECT_SE_PATH);
}

// �^�C�g���V�[���̃t�@�C���j��
void SceneTitle::DeleteSoundTitle()
{
	for (int SoundIndex = 0; SoundIndex < TITLESOUND_MAX_NUM; SoundIndex++)
	{
		DeleteSoundMem(TitleSoundHandle[SoundIndex]);
	}
}