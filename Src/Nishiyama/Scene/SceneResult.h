#pragma once
#include "Scene.h"
#include "../NumberFont/NumberFont.h"
#include "../Sound/Sound.h"

constexpr char RESULT_BG_PATH[128] = "Data/Oda/BackGround/Result.png";

constexpr char RESULT_PLAYER_PATH[128] = "Data/Oda/Player/SoloPlayer.png";

class SceneResult : public SceneBase
{
private:
	c_Number scoreFont;

	Rect_Data BG_Image;

	Rect_Data playerImage;

public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};