#pragma once
#include "Scene.h"
#include "../Shapes/Shapes.h"
#include "../Sound/Sound.h"

constexpr char TITLE_BG_PATH[128] = "Data/Oda/BackGround/Title.png";
constexpr char TITLE_SOLO_TEXT_PATH[128] = "Data/Oda/Title/Solo.png";
constexpr char TITLE_MULTI_TEXT_PATH[128] = "Data/Oda/Title/Multi.png";

constexpr char TITLE_MULTI_PLAYER_PATH[4][128] =
{
	"Data/Oda/Player/1_Player.png",
	"Data/Oda/Player/2_Player.png",
	"Data/Oda/Player/3_Player.png",
	"Data/Oda/Player/4_Player.png",
};

class SceneTitle : public SceneBase
{
private:
	int multiNum;
	Rect_Data TitleImage;

	Rect_Data TitleSoloText;
	Rect_Data TitleMultiText;
	Rect_Data Player[4];

	BGM_Data TitleBGM;

public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};