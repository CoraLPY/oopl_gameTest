#pragma once
namespace game_framework {
	class MapOne {
	public:
		MapOne();
		void LoadBitmap();
		void OnShow();
	protected:
		CMovingBitmap map1;
		CMovingBitmap num1, num2;
		int map[12][16];
		const int X, Y;		//�j�a�Ϫ����W��XY
		const int MW, MH; //�p�a�Ϫ�W,H

	};
}