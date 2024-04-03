#pragma once
#include "../Score/Score.h"

class ScoreManager
{
private:
	Score score[4];

public:
	void Init() { for (int i = 0; i < 4; i++) { score[i].Init(); } }
	void AddScore(int playerNum, int Add_int) { score[playerNum].AddScore(Add_int); }
	int GetScore(int playerNum) { return score[playerNum].GetScore(); }
};