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

// タイトルシーンのファイル読み込み
void TitleSound::LoadSoundTitle()
{
	// BGMの読み込み
	TitleSoundHandle[TITLE_BGM] = LoadSoundMem(TITLE_BGM_PATH);
	TitleSoundHandle[TITLE_SERECT_SE] = LoadSoundMem(SELECT_SE_PATH);
}

// タイトルシーンのファイル破棄
void TitleSound::DeleteSoundTitle()
{
	for (int SoundIndex = 0; SoundIndex < TITLESOUND_MAX_NUM; SoundIndex++)
	{
		DeleteSoundMem(TitleSoundHandle[SoundIndex]);
	}
}