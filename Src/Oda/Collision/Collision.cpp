#include "Collision.h"

// ��`A�Ƌ�`B�̓����蔻��̒�`
bool Collision::Rect(int Ax, int Ay, int Aw, int Ah,
				int Bx, int By, int Bw, int Bh)
{
	if (Bx < Ax + Aw &&
		Bx + Bw > Ax &&
		By + Bh > Ay &&
		By < Ay + Ah)
	{
		return true;
	}
	return false;
}

// �~A�Ɖ~B�̓����蔻��̒�`
bool Collision::Circle(int Ra, int Rb, int Xa, int Xb, int Ya, int Yb)
{
	if (((Ra + Rb) * (Ra + Rb)) > ((Xa - Xb) * (Xa - Xb)) + ((Ya - Yb) * (Ya - Yb)))
	{
		return true;
	}
	return false;
}

// ��`A�Ɠ_B�̓����蔻��̃v���g�^�C�v�錾
bool Collision::Rect_Dot(int Ax, int Ay, int Aw, int Ah, int Bx, int By)
{
	if (Ax < Bx && 
		Bx < Ax + Aw && 
		Ay < By && 
		By < Ay + Ah)
	{
		return true;
	}
	return false;
}
