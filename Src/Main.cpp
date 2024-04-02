#include "DxLib.h"

#define SCREEN_SIZE_X 960	//��ʃT�C�Y ��
#define SCREEN_SIZE_Y 640	//��ʃT�C�Y �c

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ�
	ChangeWindowMode(true);

	//��ʃT�C�Y��ݒ�
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//����������
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//�`�悷��X�N���[���𗠂ɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);


	/*�ŏ��ɂP�x������鏈��*/


	//�Q�[���̃��C�����[�v
	while (ProcessMessage() != -1)
	{
		//�G�X�P�[�v�L�[�ŏI��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//��ʂ�������
		ClearDrawScreen();

		// �� ���C���̏���


		// 1���[�v�I��
		ScreenFlip();
	}

	/*�Ō�ɂP�x������鏈��*/


	//DxLib�̌㏈��
	DxLib_End();

	return 0;
}