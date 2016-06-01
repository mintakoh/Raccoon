#include "stdafx.h"
#include "Enemy.h"
#include "resource.h"

// static ���� ����� ���� �ʱ�ȭ
int Enemy::_EnemyCount = 0;

Enemy::Enemy()
{
	// �� 
	_hEnemyLeft.LoadBitmapW(IDB_ENEMY_LEFT);
	_hEnemyRight.LoadBitmapW(IDB_ENEMY_RIGHT);
	_hEnemyLeftRed.LoadBitmapW(IDB_ENEMY_LEFT_RED);
	_hEnemyRightRed.LoadBitmapW(IDB_ENEMY_RIGHT_RED);

	// �� 
	_hSnakeLeft.LoadBitmapW(IDB_SNAKE_LEFT);
	_hSnakeRight.LoadBitmapW(IDB_SNAKE_RIGHT);

	// ����
	_hGhostLeft.LoadBitmapW(IDB_GHOST_LEFT);
	_hGhostRight.LoadBitmapW(IDB_GHOST_RIGHT);
}


Enemy::~Enemy()
{
}
