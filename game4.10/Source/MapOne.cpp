#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "MapOne.h"

namespace game_framework {
	MapOne::MapOne() :X(0),Y(0),MW(SIZE_X/16),MH(SIZE_Y/12){
		int map_init[12][16] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
								{1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1},
								{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	//4
								{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1},
								{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1},
								{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
								{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},	//8
								{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
								{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0} ,
								{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
								{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}	//12

								}; //defalt map matrix
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 16; j++) {
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
		map1.SetTopLeft(X,Y);	//set location
		map1.ShowBitmap();

		for (int i = 0; i < 16; i++) {		//left side - show 5 bitmap 
			for (int j = 0; j < 12; j++) {	//bottom side - show 4 bitmap 
				switch (map[j][i]) {
				case 0:
					num1.SetTopLeft(X + (MW*i), Y + (MH*j));	//set location
					num1.ShowBitmap();
					break;
				case 1:
					num2.SetTopLeft(X + (MW*i), Y + (MH*j));	//set location
					num2.ShowBitmap();
					break;
				default:
					ASSERT(0);		//should not show thr value except 0,1,2

				}
			}
		}
		
	}


	}
