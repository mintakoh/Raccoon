#pragma once

// 상호 참조를 피하기 위해 이름만 선언 후 .cpp 에서 헤더파일 참조
class Map;
class Enemy;
class Item;

// 아래의 점프 좌표들은 너구리가 점프할때 공중 동작을 보여주기 위함
// 공중 동작의 움직임을 특정 공식을 이용해서 계산하는 것보다
// 아래와 같이 패턴을 기술하는 것이 좀더 자연스러운 모습을 보임

//점프할때 좌표  
struct jump
{
	char x;
	char y;
	char frame; //스프라이트중에서 어떤 부분을 보여줄 건인가?
};

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

	// 제자리 점프 
	jump	_StandJump[10];

	//왼쪽 짧은 점프 
	jump	_LeftShortJump[11];

	//왼쪽 긴 점프
	jump	_LeftLongJump[17];

	// 점프를 보여줄때 필요한 카운터
	char _JumpFrame;

	// 너구리 이미지 
	CBitmap		_hLeft;
	CBitmap		_hSuperLeft;
	CBitmap		_hRight;
	CBitmap		_hSuperRight;
	CBitmap		_hUpDown;
	CBitmap		_hSuperUpDown;
	CBitmap		_hStand;
	CBitmap		_hSuperStand;
	CBitmap		_hLeftJump;
	CBitmap		_hSuperLeftJump;
	CBitmap		_hRightJump;
	CBitmap		_hSuperRightJump;
	CBitmap		_hDrop;
	CBitmap		_hDie;

	//깜짝 놀란 무늬
	CBitmap _hSurprise;

	// 충돌 검사
	void CheckCollision(Map& _Map, Item* _Item, Enemy* _Ene, int& _iItemScoreRate, int& _iTime, int& _iScore, char& _iLevel, const int& _adjY);
	void CheckCollision_Enemy(Enemy* _Ene);

	// 무적
	int ghost_time;
	bool is_ghost;
	bool is_collision;

	// 사다리 개수
	int ladder_count;

	void CheckCollision_Magma(int& _Magma_index, bool& _OnMagma);

};

