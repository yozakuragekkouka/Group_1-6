#pragma once
#include "../../Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"
#include "../../Nishiyama/Shapes/Shapes.h"

constexpr char JUST_BACK_PATH[128] = "Data/Oda/BackGround/WhiteBG.png";

class JustStop : public MiniGameBase{
protected:
	bool IsPush;//ボタンが押されたか

private:
	float X,Y;		//矩形の座標
	float LineY;	//終了線の座標
	float GetDistance(float rectY, float lineY, float height);	//矩形と線の距離を返す(矩形のY座標,線のY座標,矩形の高さ)

	int Buf_Screen;

	Rect_Data back;
public:
	~JustStop();

	void Init();
	void Step();
	void Draw();
	void Fin();

	bool GetPoint(float dist);						//矩形と線の距離からポイントを取得(矩形と線の距離)
};