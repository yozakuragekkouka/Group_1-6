#pragma once

class Collision {
public:
	// ��`A�Ƌ�`B�̓����蔻��̃v���g�^�C�v�錾
	static bool Rect(int Ax, int Ay, int Aw, int Ah,int Bx, int By, int Bw, int Bh);

	// �~A�Ɖ~B�̓����蔻��̃v���g�^�C�v�錾
	static bool Circle(int Ra, int Rb, int Xa, int Xb, int Ya, int Yb);

	// ��`A�Ɠ_B�̓����蔻��̃v���g�^�C�v�錾
	static bool Rect_Dot(int Ax, int Ay, int Aw, int Ah, int Bx, int By);
};
