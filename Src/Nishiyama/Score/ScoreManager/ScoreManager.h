#pragma once
#include "../Score/Score.h"

class ScoreManager
{
private:
	static int All_playerNum;
	static Score score[4];

public:
	static void Init() { for (int i = 0; i < 4; i++) { score[i].Init(); } }
	static void AddScore(int playerNum, int Add_int) { score[playerNum].AddScore(Add_int); }
	static int GetScore(int playerNum) { return score[playerNum].GetScore(); }

	static void SetAll_playerNum(int new_All_playerNum = 1) { All_playerNum = new_All_playerNum; }
	static int GetAll_playerNum() { return All_playerNum; }
};