#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "MapOne.h"
#include <windows.h>
#include <iostream>

namespace game_framework {
	//CAVEONE = 640x829
	MapOne::MapOne() : arr_row(16), arr_col(16), MH(51),MW(40){

		this->sx = 0;
		this->sy = 0;

		int map_init[16][16] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//4
								{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
								{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
								{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
								{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},	//8
								{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
								{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0} ,
								{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//12
								{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0} ,
								{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0} 	//16
								/*{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0} ,
								{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	//20*/

								}; //defalt map matrix


		for (int i = 0; i < arr_col; i++) {
			for (int j = 0; j < arr_row; j++) {
				map[i][j] = map_init[i][j];
			}
		}

	}


	void MapOne::LoadBitmap() {
		map1.LoadBitmap(IDB_CAVE1);
		num1.LoadBitmap(IDB_0);
		num2.LoadBitmap(IDB_1);
	}
	
	void MapOne::OnShow()

	{
		map1.SetTopLeft(sx, sy);	//set location
		map1.ShowBitmap();
		//SIZE_X / MW
		for (int i = sx / MW; i < (SIZE_X / MW);i++) {		//left side - show 5 bitmap
			for (int j = sy / MH; j < (SIZE_Y / MH)  ; j++) {	//bottom side - show 4 bitmap 
				int x = i * MW - sx;	//在screen 左上角開始算的screen x	
				int y = i * MH - sy;	//screen y

				//0=run ;1=阻礙物
				switch (map[j][i]) {
				case 0:
					num1.SetTopLeft(sx+(i*MW),sy+(j*MH));	//set location
					num1.ShowBitmap();
					break;
				case 1:
					num2.SetTopLeft(sx + (i*MW), sy + (j*MH));	//set location
					num2.ShowBitmap();
					break;
				default:
					ASSERT(0);		//should not show thr value except 0,1,2

				}
			
			}
		}
		
	}

	void MapOne::SetSX(int add_sx) {
		sx +=  add_sx;	//在screen 左上角開始算的screen x	

		//map1.SetTopLeft(newX, sy);	//set location
		//map1.ShowBitmap();
	}
	void MapOne::SetSY(int add_sy) {
		sy += add_sy;	//在screen 左上角開始算的screen x	
	}

	int MapOne::GetMH() { return MH; }
	int MapOne::GetMW() { return MW; }


	bool MapOne::IsEmpty(int x, int y) {
		int gx = x/MW;
		int gy = y/MH;

		if (map[gy][gx] == 0) {
			return true;
		}else{
			return false;
		}
		//return map[gx][gy] == 0 ? true: false;
	}



	}
