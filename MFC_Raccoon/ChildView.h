
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once


// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	void GameCycle();
	bool _bIsDrawAll;
	char _GameState;
	int _iAni;
	char _iLevel;
	char _cMap[26][33];
	char _EnemyCount;

	struct Raccoon
	{
		int x;			//x좌표
		int y;			//y좌표
		char state;		//너구리상태 (오토마다 참조)
		bool step;		//움직일때 애니메이션
		char speedx;	//x속도
		char speedy;	//y속도
	};

	struct Enemy
	{
		int x;			//x좌표
		int y;			//y좌표
		int alpha;		//뱀 희미하다 선명하게
		char speed;		//속도
		bool state;		//방향(좌우)
		bool type;		//일반적인 적, 뱀
	};

	struct Item
	{
		int x;
		int y;
		char ch;
	};

	struct jump
	{
		char x;
		char y;
		char frame;
	};

	Raccoon _Rac;
	Enemy	_Ene[7];
	Item	_Item[12];



	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

