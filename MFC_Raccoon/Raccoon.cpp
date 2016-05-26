#include "stdafx.h"
#include <mmsystem.h>
#include "Raccoon.h"
#include "resource.h"
#include "Enemy.h"
#include "Item.h"
#include "Map.h"
#include "Game.h"

// static 변수 사용을 위해 초기화
char Raccoon::_iLive = 0;

Raccoon::Raccoon()
: _JumpFrame(0)
{
	// 제자리 점프 
	_StandJump[0] = { 1, -5, 0 };
	_StandJump[1] = { 1, -5, 0 };
	_StandJump[2] = { -1, -5, 0 };
	_StandJump[3] = { -1, -5, 1 };
	_StandJump[4] = { -1, -5, 1 };
	_StandJump[5] = { -1, 5, 1 };
	_StandJump[6] = { 1, 5, 1 };
	_StandJump[7] = { 1, 5, 0 };
	_StandJump[8] = { 0, 5, 0 };
	_StandJump[9] = { 0, 5, 0 };

	//왼쪽 짧은 점프 
	_LeftShortJump[0] = { -5, -5, 0 };
	_LeftShortJump[1] = { -5, -4, 0 };
	_LeftShortJump[2] = { -5, -4, 1 };
	_LeftShortJump[3] = { -5, -4, 1 };
	_LeftShortJump[4] = { -5, -3, 1 };
	_LeftShortJump[5] = { 0, 0, 1 };
	_LeftShortJump[6] = { -5, 3, 2 };
	_LeftShortJump[7] = { -5, 4, 2 };
	_LeftShortJump[8] = { -5, 4, 2 };
	_LeftShortJump[9] = { -5, 4, 2 };
	_LeftShortJump[10] = { -5, 5, 3 };

	//왼쪽 긴 점프 
	_LeftLongJump[0] = { -5, -6, 0 };
	_LeftLongJump[1] = { -5, -6, 0 };
	_LeftLongJump[2] = { -5, -5, 0 };
	_LeftLongJump[3] = { -5, -5, 1 };
	_LeftLongJump[4] = { -5, -4, 1 };
	_LeftLongJump[5] = { -5, -3, 1 };
	_LeftLongJump[6] = { -5, -2, 1 };
	_LeftLongJump[7] = { -5, -1, 1 };
	_LeftLongJump[8] = { 0, 0, 1 };
	_LeftLongJump[9] = { -5, 1, 2 };
	_LeftLongJump[10] = { -5, 2, 2 };
	_LeftLongJump[11] = { -5, 3, 2 };
	_LeftLongJump[12] = { -5, 4, 2 };
	_LeftLongJump[13] = { -5, 5, 2 };
	_LeftLongJump[14] = { -5, 5, 2 };
	_LeftLongJump[15] = { -5, 6, 2 };
	_LeftLongJump[16] = { -5, 6, 3 };

	// 너구리
	_hLeft.LoadBitmapW(IDB_LEFT);
	_hStand.LoadBitmapW(IDB_STAND);
	_hRight.LoadBitmapW(IDB_RIGHT);
	_hUpDown.LoadBitmapW(IDB_UPDOWN);
	_hLeftJump.LoadBitmapW(IDB_LEFT_JUMP);
	_hRightJump.LoadBitmapW(IDB_RIGHT_JUMP);
	_hDrop.LoadBitmapW(IDB_DROP);
	_hDie.LoadBitmapW(IDB_DIE);

	//SURPRISE
	_hSurprise.LoadBitmapW(IDB_SURPRISE);
}


Raccoon::~Raccoon()
{
}


void Raccoon::CheckCollision(Map& _Map, Item* _Item, Enemy* _Ene, int& _iItemScoreRate, int& _iScore)
{
	static int x1, y1, x2, y2;
	static int xx1, yy1, xx2, yy2;

	if (state == 2 || state == 6 || state == 7){
		x1 = x + 10;
		y1 = y + 5;
		x2 = x + 30;
		y2 = y + 45;
	}

	else{
		x1 = x + 20;
		y1 = y + 5;
		x2 = x + 40;
		y2 = y + 40;
	}

	if (state == 2 || state == 3){
		if (_Map._cMap[y2 / 25][x1 / 25] == 'E' || _Map._cMap[y2 / 25 + 1][x1 / 25] == '.'){
			xx1 = (x1 / 25 * 25) + 5;
			xx2 = ((x1 / 25 + 1) * 25) - 5;
			if ((xx1 > x1 && xx1 <x2) || (xx2 > x1 && xx2 < x2)){
				state = 10;
				return;
			}
		}
		if (_Map._cMap[y2 / 25][x2 / 25] == 'E' || _Map._cMap[y2 / 25 + 1][x2 / 25] == '.') {
			xx1 = (x2 / 25 * 25) + 5;
			xx2 = ((x2 / 25 + 1) * 25) - 5;
			if ((xx1 > x1 && xx1 < x2) || (xx2 > x1 && xx2 < x2)) {
				state = 10;
				return;
			}
		}
	}

	//과일, 항아리 충돌 검사
	char i;

	for (i = 0; i < Item::_ItemCount; i++){
		if (_Item[i].ch >= 'M'){
			xx1 = _Item[i].x + 10;
			yy1 = _Item[i].y + 30;
			xx2 = _Item[i].x + 40;
			yy2 = _Item[i].y + 40;

			if ((xx1 > x1 && xx1 < x2 && yy1 > y1 && yy1 < y2) ||
				(xx1 > x1 && xx1 < x2 && yy2 > y1 && yy2 < y2) ||
				(xx2 > x1 && xx2 < x2 && yy1 > y1 && yy1 < y2) ||
				(xx2 > x1 && xx2 < x2 && yy2 > y1 && yy2 < y2)){

				PlaySound(MAKEINTRESOURCE(IDR_RAC_EAT), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

				if (_Item[i].ch >= 'Q') Item::_iEat++;

				if (_Item[i].ch == 'N' || _Item[i].ch == 'M'){
					PlaySound(MAKEINTRESOURCE(IDR_SNAKE), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

					_Ene[Enemy::_EnemyCount].x = _Item[i].x;
					_Ene[Enemy::_EnemyCount].y = _Item[i].y;
					_Ene[Enemy::_EnemyCount].type = FALSE;
					_Ene[Enemy::_EnemyCount].alpha = 10;

					if (_Item[i].ch == 'N') {
						_Ene[Enemy::_EnemyCount].state = TRUE;
						_Ene[Enemy::_EnemyCount].speed = -1;

					}
					else {
						_Ene[Enemy::_EnemyCount].state = FALSE;
						_Ene[Enemy::_EnemyCount].speed = 1;
					}

					_Item[i].ch = '.';
					Enemy::_EnemyCount++;
				}
				else{
					//점수 표시 준비
					//나중에 점수 표시하고 '.'으로 교체
					_Item[i].ch = '*';
					//점수 계산
					_iItemScoreRate *= 2;
					_iScore += _iItemScoreRate;
				}
			}
		}
	}
}

void Raccoon::CheckCollision_Enemy(Enemy* _Ene)
{
	static int x1, y1, x2, y2;
	static int xx1, yy1, xx2, yy2;

	if (state == 2 || state == 6 || state == 7){
		x1 = x + 10;
		y1 = y + 5;
		x2 = x + 30;
		y2 = y + 45;
	}

	else if (state == 3 || state == 8 || state == 9){
		x1 = x + 20;
		y1 = y + 5;
		x2 = x + 40;
		y2 = y + 45;
	}

	else{
		x1 = x + 5;
		y1 = y + 5;
		x2 = x + 40;
		y2 = y + 45;
	}

	char i;

	for (i = 0; i < Enemy::_EnemyCount; i++){
		if (_Ene[i].alpha == 255){
			xx1 = _Ene[i].x + 7;
			yy1 = _Ene[i].y + 5;
			xx2 = _Ene[i].x + 43;
			yy2 = _Ene[i].y + 50;

			if ((x1 > xx1 && x1 < xx2 && y1 > yy1 && y1 < yy2) ||
				(x1 > xx1 && x1 < xx2 && y2 > yy1 && y2 < yy2) ||
				(x2 > xx1 && x2 < xx2 && y1 > yy1 && y2 < yy2) ||
				(x2 > xx1 && x2 < xx2 && y2 > yy1 && y2 < yy2))
				state = 10;

		}
	}
}