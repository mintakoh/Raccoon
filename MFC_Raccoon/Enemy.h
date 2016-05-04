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
	bool type;		//일반적인 적, 뱀
};

