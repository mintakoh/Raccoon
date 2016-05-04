#pragma once

class Raccoon
{
public:
	Raccoon();
	~Raccoon();

	int x;				// x좌표
	int y;				// y좌표 
	char state;			// 너구리 상태 (왼쪽 , 오른쪽 , 점프 ......) [너구리상태전이도 참고]
	BOOL step;			// 움직일때 에니메이션을 위해 
	char speedx;		// 속도 
	char speedy;		// 속도 
};

