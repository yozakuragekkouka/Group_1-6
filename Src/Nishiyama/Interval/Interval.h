#pragma once
#include "../GameState/GameState.h"
#include "../Shapes/Shapes.h"

constexpr char INTERVAL_BG_PATH[128] = "Data/Oda/BackGround/Play.png";

constexpr char INTERVAL_PLAYER_PATH[128] = "Data/Oda/Player/SoloPlayer.png";

constexpr int MINIGAME_STAY_FRAME = 120;
constexpr int MINIGAME_START_FRAME = 120;
constexpr int MINIGAME_END_FRAME = 120;
constexpr int MINIGAME_END_STEP_FRAME = 180;

enum class IntervalState
{
	Stay_MiniGame,
	Start_MiniGame,
	Playing_MiniGame,
	End_MiniGame
};

class Interval
{
private:
	Rect_Data BG_Image;

	Rect_Data playerImage;

	IntervalState state;
	int intervalFrameCount;

	bool All_Fin;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	void End_Step();

	bool GetAll_Fin() const { return All_Fin; }
	IntervalState GetState() const { return state; }
	void SetState(IntervalState NewState) { state = NewState; }
};