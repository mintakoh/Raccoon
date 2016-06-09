#include "stdafx.h"
#include "Enemy.h"
#include "resource.h"

// static 변수 사용을 위해 초기화
int Enemy::_EnemyCount = 0;

Enemy::Enemy()
{
	// 적 
	_hEnemyLeft.LoadBitmapW(IDB_ENEMY_LEFT);
	_hEnemyRight.LoadBitmapW(IDB_ENEMY_RIGHT);
	_hEnemyLeftRed.LoadBitmapW(IDB_ENEMY_LEFT_RED);
	_hEnemyRightRed.LoadBitmapW(IDB_ENEMY_RIGHT_RED);

	// 뱀 
	_hSnakeLeft.LoadBitmapW(IDB_SNAKE_LEFT);
	_hSnakeRight.LoadBitmapW(IDB_SNAKE_RIGHT);

	// 유령
	_hGhostLeft.LoadBitmapW(IDB_GHOST_LEFT);
	_hGhostRight.LoadBitmapW(IDB_GHOST_RIGHT);
}


Enemy::~Enemy()
{
}
