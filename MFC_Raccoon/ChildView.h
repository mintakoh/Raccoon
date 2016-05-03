
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once

#pragma comment(lib, "winmm")
#include <mmsystem.h>
#include "afxwin.h"



// 게임에서 사용하는 키 지정 
#define LEFT		VK_LEFT
#define RIGHT		VK_RIGHT
#define UP			VK_UP
#define DOWN		VK_DOWN
#define	JUMP		VK_SPACE

// 처음에 주어지는 너구리 수 
#define	LIVE		7

// 마지막 레벨 
#define LAST_LEVEL	4

//너구리
struct Raccoon
{
	int x;			//x좌표
	int y;			//y좌표
	char state;		//너구리상태 (오토마다 참조)
	bool step;		//움직일때 애니메이션
	char speedx;	//x속도
	char speedy;	//y속도
};

//적 (적과 뱀을 같이 처리, 차이는 적은 알파값을 사용하지 않는다, 뱀만 사용)
struct Enemy
{
	int x;			//x좌표
	int y;			//y좌표
	int alpha;		//뱀 희미하다 선명하게
	char speed;		//속도
	bool state;		//방향(좌우)
	bool type;		//일반적인 적, 뱀
};

//과일, 항아리 
struct Item
{
	int x;
	int y;
	char ch;
};

//점프할때 좌표  
struct jump
{
	char x;
	char y;
	char frame; //스프라이트중에서 어떤 부분을 보여줄 건인가?
};


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
	CRect rect;
	
	void HandleKeys();

	void GameCycle();
	void GameIntro();
	void GamePlay();
	void DrawDigit(CDC& cDC, int x, int y, int score, CBitmap& cBit, int cipher = 0, COLORREF crTransColor = RGB(0, 0, 0));
	void GameClear();
	void GameOver();
	bool _bIsDrawAll;
	char _GameState;
	int _iAni;
	char _iLevel;
	char _cMap[26][33];
	int _EnemyCount;


	Raccoon _Rac;
	Enemy	_Ene[7];
	Item	_Item[12];
	jump	_StandJump[10];
	jump	_LeftShortJump[11];
	jump	_LeftLongJump[17];

	void LoadMap();
	void CheckCollision();
	void CheckCollision_Enemy();
	void Init();

	//더블 버퍼링을 위해  
	CBitmap		_cBit;

	//먹은 과일 수
	char		_iEat;

	//먹은 아이템의 점수 표시 시간 
	char		_ScoreShow;

	// 남은 너구리 수
	char		_iLive;

	// 남은 시간
	int			_iTime;

	// 점수
	int			_iScore;

	


	// 기본 맵 구성 이미지 
	CBitmap _hMap;
	CBitmap _hMapEle[6];

	//LETS
	CBitmap _hLets;
	// 'SCORE'
	CBitmap		_hScore;
	//Gameover
	CBitmap		_hGameOver;
	//BONUS
	CBitmap		_hBonus;
	//NEXT
	CBitmap		_hNext;
	//ENDING
	CBitmap		_hEnding;

	// 숫자
	CBitmap		_hDigit;
	CBitmap		_hDigit_sm;

	// 항아리
	CBitmap		_hPot;

	//과일
	CBitmap		_hFruit[4];
	
	// 너구리 이미지 
	CBitmap		_hLeft;
	CBitmap		_hRight;
	CBitmap		_hUpDown;
	CBitmap		_hStand;
	CBitmap		_hLeftJump;
	CBitmap		_hRightJump;
	CBitmap		_hDrop;
	CBitmap		_hDie;

	//깜짝 놀란 무늬
	CBitmap _hSurprise;

	// 적
	CBitmap		_hEnemyRight;
	CBitmap		_hEnemyLeft;
	CBitmap		_hEnemyRightRed;
	CBitmap		_hEnemyLeftRed;

	//뱀
	CBitmap		_hSnakeLeft;
	CBitmap		_hSnakeRight;

	//아기
	CBitmap		_hBaby;

	// 먹은 과일이나 항아리 점수 증가폭 (2배씩 증가)
	int			_iItemScoreRate;

	// 점프를 보여줄때 필요한 카운터
	char _JumpFrame;
	// 너구리가 죽어서 떨어질때 음악 연주 상태
	BOOL _bIsDrop_Sound;


	
};

