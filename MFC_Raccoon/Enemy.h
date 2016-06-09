#pragma once


//적 (적과 뱀을 같이 처리, 차이는 적은 알파값을 사용하지 않는다, 뱀만 사용)
class Enemy
{
public:
	Enemy();
	~Enemy();

	int x;			//x좌표
	int y;			//y좌표
	int alpha;		//뱀 희미하다 선명하게
	char speed;		//속도
	bool state;		//방향(좌우)
	char type;		//일반적인 적 0, 뱀 1, 유령 2

	char speed_y;	// y 속도 (유령)
	bool state_y;	// y 방향 (유령)

	// 적
	CBitmap		_hEnemyRight;
	CBitmap		_hEnemyLeft;
	CBitmap		_hEnemyRightRed;
	CBitmap		_hEnemyLeftRed;

	//뱀
	CBitmap		_hSnakeLeft;
	CBitmap		_hSnakeRight;

	//유령
	CBitmap		_hGhostRight;
	CBitmap		_hGhostLeft;

	static int _EnemyCount;

};

