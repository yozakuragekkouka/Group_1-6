#include "DxLib.h"
#include "Common.h"
#include "Nishi/Input/Input.h"
#include "Nishi/FrameRate/FrameRate.h"
#include "Nishi/NumberFont/NumberFont.h"
#include "Nishi/NumberFont/NumberFontData.h"
#include "Nishi/Scene/Scene.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//ウィンドウの状態を設定
	ChangeWindowMode(true);

	//画面サイズを設定
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//描画するスクリーンを裏に設定
	SetDrawScreen(DX_SCREEN_BACK);


	/*最初に１度だけやる処理*/
	Input::AllInputInit();

	SceneManager scene_manager;
	scene_manager.SceneInit();

	//ゲームのメインループ
	while (ProcessMessage() != -1)
	{
		if (FrameRateAdmin())
		{
			Input::Get_Key_Input_Log();

			//エスケープキーで終了
			if (CheckHitKey(KEY_INPUT_ESCAPE))
			{
				break;
			}

			//画面を初期化
			ClearDrawScreen();

			// ↓ メインの処理
			if (scene_manager.SceneLoop())
			{
				break;
			}

			//FPS計算
			CalcFPS();

			//FPS表示
			DrawFPS();

			// 1ループ終了
			ScreenFlip();
		}
	}

	/*最後に１度だけやる処理*/
	scene_manager.SceneFin();

	//DxLibの後処理
	DxLib_End();

	return 0;
}