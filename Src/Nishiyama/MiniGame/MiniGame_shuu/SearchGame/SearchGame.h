#pragma once
#include "../../MiniGameBase/MiniGameBase.h"
#include "../../../Shapes/Shapes.h"

constexpr char SEARCH_BACK_PATH[128] = "Data/Oda/BackGround/WhiteBG.png";
constexpr char LIGHT_PATH[128] = "Data/Image/Nishiyama/nushimegane_naka.png";
constexpr char BOMB_PATH[128] = "Data/Image/Nishiyama/Bomb.png";
constexpr char MUSHIMEGANE_PATH[128] = "Data/Image/Nishiyama/nushimegane_soto.png";

class SearchGame : public MiniGameBase
{
private:
	int Buf_Screen;

	Rect_Data back;
	Rect_Data light;

	Rect_Data bomb;
	Rect_Data mushimegane;

public:
	~SearchGame();

	void Init();
	void Step();
	void Draw();
	void Fin();
};