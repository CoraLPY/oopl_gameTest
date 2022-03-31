#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Player.h"
#include "MapOne.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	Player::Player()
	{
		Initialize();
	}

	int Player::GetX1()
	{
		return x;
	}

	int Player::GetY1()
	{
		return y;
	}

	int Player::GetX2()
	{
		return x + player.Width();
	}

	int Player::GetY2()
	{
		return y + player.Height();
	}

	void Player::Initialize()
	{
		const int X_POS = 100; //80
		const int Y_POS = 100;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	void Player::LoadBitmap()
	{
		
		player.AddBitmap(IDB_GIRLDOWN1, RGB(0, 0, 0));
		player.AddBitmap(IDB_GIRLDOWN2, RGB(0, 0, 0));
		player.AddBitmap(IDB_GIRLDOWN3, RGB(0, 0, 0));
		player.AddBitmap(IDB_GIRLDOWN4, RGB(0, 0, 0));
		player.AddBitmap(IDB_GIRLDOWN5, RGB(0, 0, 0));
		player.AddBitmap(IDB_GIRLDOWN6, RGB(0, 0, 0));
		player.AddBitmap(IDB_GIRLDOWN7, RGB(0, 0, 0));
	
	}

	void Player::OnMove(MapOne *map)
	{
		const int STEP_SIZE = 2;
		player.OnMove();
		if (isMovingLeft) {
			
			if (map->IsEmpty((GetX2()- STEP_SIZE),GetY2())) {
				x -= STEP_SIZE;
				map->SetSX(-1*STEP_SIZE);
			}
			
		}
			
		if (isMovingRight) {
			
			if (map->IsEmpty((GetX2() + STEP_SIZE), GetY2())) {
				x += STEP_SIZE;
				map->SetSX( STEP_SIZE);
			}

			
		}
			
		if (isMovingUp) {
		
			if (map->IsEmpty(GetX2(), (GetY2() - STEP_SIZE))) {
				y -= STEP_SIZE;
				map->SetSY(-1 * STEP_SIZE);
			}
		}
			
		if (isMovingDown) {
			//y += STEP_SIZE;
			if (map->IsEmpty(GetX2(), (GetY2() +STEP_SIZE))) {
				y += STEP_SIZE;
				map->SetSY(STEP_SIZE);
			}
		}
			
	}

	void Player::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void Player::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void Player::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void Player::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void Player::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void Player::OnShow()
	{
		player.SetTopLeft(x, y);
		player.OnShow();
	}
}