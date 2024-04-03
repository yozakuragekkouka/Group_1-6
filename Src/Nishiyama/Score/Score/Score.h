#pragma once

class Score
{
protected:
	int score;

public:
	void Init() { score = 0; }

	void AddScore(int Add_int) { score += Add_int; }

	int GetScore() const { return score; }
};