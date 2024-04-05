#include "DxLib.h"
#include "Sound.h"

TitleSound::TitleSound()
{
	for (int SoundIndex = 0; SoundIndex < TITLESOUND_MAX_NUM; SoundIndex++)
	{
		TitleSoundHandle[SoundIndex] = 0;
	}
}
TitleSound::~TitleSound(){}

// �^�C�g���V�[���̃t�@�C���ǂݍ���
void TitleSound::LoadSoundTitle()
{
	// BGM�̓ǂݍ���
	TitleSoundHandle[TITLE_BGM] = LoadSoundMem(TITLE_BGM_PATH);
	TitleSoundHandle[TITLE_SERECT_SE] = LoadSoundMem(SELECT_SE_PATH);
}

// �^�C�g���V�[���̃t�@�C���j��
void TitleSound::DeleteSoundTitle()
{
	for (int SoundIndex = 0; SoundIndex < TITLESOUND_MAX_NUM; SoundIndex++)
	{
		DeleteSoundMem(TitleSoundHandle[SoundIndex]);
	}
}