#pragma once
#include "../MiniGameBase/MiniGameBase.h"
#include "../../GameState/GameState.h"

enum class MiniGameKind
{
	GAME_NONE = -1,
	SearchGame,

	MiniGameKindNum
};

class MiniGameManager
{
private:
	MiniGameBase* miniGame;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	void MiniGameInit();
	void MiniGameFin();

	void Set_NewGame();
	void Delete_Game();

	bool Get_MiniGameisFinish() { return miniGame->GetisFinish(); }
	bool Get_MiniGameisClear() { return miniGame->GetisClear(); }
};