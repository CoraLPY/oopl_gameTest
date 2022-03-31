#pragma once
namespace game_framework {
	class MapOne {
	public:
		MapOne();
		void LoadBitmap();
		void OnShow();
		bool IsEmpty(int x, int y); //check 有沒有阻礙物
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
		//const int X, Y;		//大地圖的左上角點座標XY
		int sx;	//SCREEN的左上角在地圖上SCREEN的點座標 (地圖點座標)
		int sy; //SCREEN的左上角在地圖上SCREEN的點座標 (地圖點座標)
		const int MW;	//小地圖的W,H
		const int MH; //小地圖的W,H

	};
}