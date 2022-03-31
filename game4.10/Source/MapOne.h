#pragma once
namespace game_framework {
	class MapOne {
	public:
		MapOne();
		void LoadBitmap();
		void OnShow();
		bool IsEmpty(int x, int y); //check ���S����ê��
		void SetSX(int new_sx);
		void SetSY(int new_sy);
		int GetMW();
		int GetMH();
		int ScreenX(int x);
		int ScreenY(int y);
	protected:
		CMovingBitmap map1;
		CMovingBitmap num1, num2;
		const int arr_row;
		const int arr_col;
		int map[16][16];  
		//const int X, Y;		//�j�a�Ϫ����W���I�y��XY
		int sx;	//SCREEN�����W���b�a�ϤWSCREEN���I�y�� (�a���I�y��)
		int sy; //SCREEN�����W���b�a�ϤWSCREEN���I�y�� (�a���I�y��)
		const int MW;	//�p�a�Ϫ�W,H
		const int MH; //�p�a�Ϫ�W,H

	};
}