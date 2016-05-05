#include "stdafx.h"
#include "Enemy.h"
#include "resource.h"

int Enemy::_EnemyCount = 0;

Enemy::Enemy()
{
	// Àû 
	_hEnemyLeft.LoadBitmapW(IDB_ENEMY_LEFT);
	_hEnemyRight.LoadBitmapW(IDB_ENEMY_RIGHT);
	_hEnemyLeftRed.LoadBitmapW(IDB_ENEMY_LEFT_RED);
	_hEnemyRightRed.LoadBitmapW(IDB_ENEMY_RIGHT_RED);

	// ¹ì 
	_hSnakeLeft.LoadBitmapW(IDB_SNAKE_LEFT);
	_hSnakeRight.LoadBitmapW(IDB_SNAKE_RIGHT);
}


Enemy::~Enemy()
{
}
