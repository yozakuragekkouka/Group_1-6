#pragma once
#include "Scene.h"
#include "../Interval/Interval.h"
#include "../MiniGame/MiniGameManager/MiniGameManager.h"
#include "../GameState/GameState.h"
#include "../Sound/Sound.h"

class ScenePlay : public SceneBase
{
private:
	int now_playerNumber;
	GameState gameState;
	Interval interval;
	MiniGameManager minigame_manager;

	BGM_Data PlayBGM;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();


};