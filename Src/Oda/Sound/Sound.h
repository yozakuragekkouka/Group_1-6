#pragma once

// Title
#define TITLE_BGM_PATH	"Data/Oda/Sound/TitleBGM.mp3"
#define SELECT_SE_PATH	"Data/Oda/Sound/SelectSE.mp3"

enum SoundTitle {
	TITLE_BGM,			// 0:タイトル画面のBGM
	TITLE_SERECT_SE,	// 1:選択音

	TITLESOUND_MAX_NUM,	// 2:タイトル
};

class TitleSound {
private:
	int TitleSoundHandle[TITLESOUND_MAX_NUM];

public:
	TitleSound();
	~TitleSound();

	// タイトルシーンのファイル読み込み
	void LoadSoundTitle();

	// タイトルシーンのファイル破棄
	void DeleteSoundTitle();
};

