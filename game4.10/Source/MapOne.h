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
		const int X, Y;		//大地圖的左上角XY
		const int MW, MH; //小地圖的W,H

	};
}