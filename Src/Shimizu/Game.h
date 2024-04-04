#pragma once
#include "../../Src/Nishiyama/MiniGame/MiniGameBase/MiniGameBase.h"

class MiniGame : public MiniGameBase{
protected:
	bool IsPush;//ボタンが押されたか
	int handle;

private:
	float X,Y;		//矩形の座標
	float LineY;	//終了線の座標
	float GetDistance(float rectY, float lineY);	//矩形と線の距離を返す(矩形のY座標,線のY座標)
public:
	void Init();
	void Play();
	void Draw();
	void Fin();

	float GetPoint(float dist);						//矩形と線の距離からポイントを取得(矩形と線の距離)
};