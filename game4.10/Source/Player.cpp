#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Player.h"


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
		const int X_POS = 20;
		const int Y_POS = 50;
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

	void Player::OnMove()
	{
		const int STEP_SIZE = 2;
		player.OnMove();
		if (isMovingLeft) {
			
			//player.ShowBitmap(pLeft);
			x -= STEP_SIZE;
		}
			
		if (isMovingRight) {
			//player.ShowBitmap(pRight);
			x += STEP_SIZE;
		}
			
		if (isMovingUp) {
			//player.ShowBitmap(pUp);
			y -= STEP_SIZE;
		}
			
		if (isMovingDown) {
			//player.ShowBitmap(pDown);
			y += STEP_SIZE;
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