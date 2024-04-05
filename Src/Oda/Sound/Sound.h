#pragma once

// Title
#define TITLE_BGM_PATH	"Data/Oda/Sound/TitleBGM.mp3"
#define SELECT_SE_PATH	"Data/Oda/Sound/SelectSE.mp3"

enum SoundTitle {
	TITLE_BGM,			// 0:�^�C�g����ʂ�BGM
	TITLE_SERECT_SE,	// 1:�I����

	TITLESOUND_MAX_NUM,	// 2:�^�C�g��
};

class TitleSound {
private:
	int TitleSoundHandle[TITLESOUND_MAX_NUM];

public:
	TitleSound();
	~TitleSound();

	// �^�C�g���V�[���̃t�@�C���ǂݍ���
	void LoadSoundTitle();

	// �^�C�g���V�[���̃t�@�C���j��
	void DeleteSoundTitle();
};

