
// ChildView.cpp : CChildView 클래스의 구현
// 
#include "stdafx.h"
#include "MFC_Raccoon.h"
#include "ChildView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildView

CChildView::CChildView()
	: _bIsDrawAll(false)
	, _GameState(0)
	, _iAni(0)
	, _iLevel(1)
	, _EnemyCount(0)
	, _iEat(0)
	, _ScoreShow(0)
	, _iLive(0)
	, _iTime(0)
	, _iScore(0)
	, _iItemScoreRate(0)
	, _JumpFrame(0)
	, _bIsDrop_Sound(FALSE)
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



	//이미지 처리 맵 구성품
	_hMapEle[0].LoadBitmapW(IDB_MAP_A);
	_hMapEle[1].LoadBitmapW(IDB_MAP_B);
	_hMapEle[2].LoadBitmapW(IDB_MAP_C);
	_hMapEle[3].LoadBitmapW(IDB_MAP_D);
	_hMapEle[4].LoadBitmapW(IDB_MAP_E);
	_hMapEle[5].LoadBitmapW(IDB_MAP_F);

	//LETS
	_hLets.LoadBitmapW(IDB_LETS);
	//SCORE
	_hScore.LoadBitmapW(IDB_SCORE);
	//GAMEOVER
	_hGameOver.LoadBitmapW(IDB_GAMEOVER);
	//BONUS
	_hBonus.LoadBitmapW(IDB_BONUS);
	//NEXT
	_hNext.LoadBitmapW(IDB_NEXT);
	//ENDING
	_hEnding.LoadBitmapW(IDB_ENDING);

	// 숫자 
	_hDigit.LoadBitmapW(IDB_DIGIT);
	_hDigit_sm.LoadBitmapW(IDB_DIGIT_SM);

	// 항아리 
	_hPot.LoadBitmapW(IDB_MAP_N);

	// 과일 
	_hFruit[0].LoadBitmapW(IDB_MAP_Q);
	_hFruit[1].LoadBitmapW(IDB_MAP_R);
	_hFruit[2].LoadBitmapW(IDB_MAP_S);
	_hFruit[3].LoadBitmapW(IDB_MAP_T);

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

	//적
	_hEnemyLeft.LoadBitmapW(IDB_ENEMY_LEFT);
	_hEnemyRight.LoadBitmapW(IDB_ENEMY_RIGHT);
	_hEnemyLeftRed.LoadBitmapW(IDB_ENEMY_LEFT_RED);
	_hEnemyRightRed.LoadBitmapW(IDB_ENEMY_RIGHT_RED);
	
	//뱀
	_hSnakeLeft.LoadBitmapW(IDB_SNAKE_LEFT);
	_hSnakeRight.LoadBitmapW(IDB_SNAKE_RIGHT);
	
	//아기
	_hBaby.LoadBitmapW(IDB_BABY);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
//	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::GameIntro()
{
	CClientDC dc(this);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	//시간
	if (_iAni == 1000)
		_iAni = 0;
	else
		_iAni++;

	//게임 화면(인트로 -> 게임화면(맵)) 전환
	if (_iAni >= 1000)
		_GameState = 1;

	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	GetClientRect(&rect);
	
	if (_cBit.m_hObject == NULL)
		_cBit.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memdc.SelectObject(&_cBit);

	//인트로
	CBrush backBrush;
	backBrush.CreateSolidBrush(RGB(0, 0, 0));
	if (_iAni == 1)
		memdc.FillRect(&rect, &backBrush);
	else {
		memdc.FillRect(CRect(120, 430, 900, 500), &backBrush);
	}

	static BOOL b;		//애니메이션 효과를 위해 	
	//너구리 줄서 와서 자리 잡기 까지 
	if (_iAni <= 171) {

		b = !b;
		objectdc.SelectObject(_hLeft);

		if (_iAni <= 50)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else
			memdc.TransparentBlt(720, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni >= 50 && _iAni <= 70)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else if (_iAni >= 70)
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni >= 70 && _iAni <= 90)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else if (_iAni >= 90)
			memdc.TransparentBlt(520, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni >= 90 && _iAni <= 110)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else if (_iAni >= 110)
			memdc.TransparentBlt(420, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni >= 110 && _iAni <= 130)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else if (_iAni >= 130)
			memdc.TransparentBlt(320, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni >= 130 && _iAni <= 150)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else if (_iAni >= 150)
			memdc.TransparentBlt(220, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni >= 150 && _iAni <= 170)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else if (_iAni >= 170)
			memdc.TransparentBlt(120, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		//너구리 몸 흔들기 -> Dance ㅡㅡ;;
	}
	else if (_iAni < 437) {
		objectdc.SelectObject(&_hStand);
		for (int i = 120; i <= 520; i += 100)
			memdc.TransparentBlt(i, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni < 250)
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, (1 - _iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));
		else
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni > 220 && _iAni < 255) {
			objectdc.SelectObject(_hSurprise);
			memdc.TransparentBlt(640, 435, 29, 21, &objectdc, 0, 0, 29, 21, RGB(0, 0, 0));
		}

		objectdc.SelectObject(_hStand);
		memdc.TransparentBlt(720, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));
	}
	else {
		objectdc.SelectObject(_hRight);
		for (int i = 120; i <= 520; i += 100)
			memdc.TransparentBlt(i, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));

		objectdc.SelectObject(_hStand);
		memdc.TransparentBlt(620, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));

		objectdc.SelectObject(_hSurprise);
		memdc.TransparentBlt(640, 435, 29, 21, &objectdc, 0, 0, 29, 21, RGB(0, 0, 0));

		objectdc.SelectObject(_hLeft);
		memdc.TransparentBlt(720, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));
	}

	if (_iAni == 171) {
		objectdc.SelectObject(_hLets);
		memdc.BitBlt(220, 120, 455, 218, &objectdc, 0, 0, SRCCOPY);

		PlaySound(MAKEINTRESOURCE(IDR_INTRO), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	}

	Invalidate(false);
}

void CChildView::GamePlay()
{
	GetClientRect(&rect);
	CClientDC dc(this);
	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	CBitmap* OldBit;

	if (_cBit.m_hObject == NULL)
		_cBit.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	OldBit = memdc.SelectObject(&_cBit);

	CPen pen, *OldPen;
	CBrush brush, *OldBrush;

	char i;

	//// 시간 바를 표시할 브러시와 펜 
	pen.CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
	OldPen = memdc.SelectObject(&pen);
	brush.CreateSolidBrush(RGB(25, 184, 5));
	OldBrush = memdc.SelectObject(&brush);

	////에니메이션 구현을 위해 	
	////너구리가 죽으면 움직임을 멈추는 것들은 _iTime을 기준으로 에니메이션
	////너구리가 죽으면서 하는 움직임은 _iAni을 이용 	
	_iAni++;

	//// Play종료 조건 

	//// 과일 다 먹음 
	//// _ScoreShow == 1 을 한 이유는 마지막으로 먹은 과일 점수 까지 보여주려고 
	if (_iEat == 8 && _ScoreShow == 1) {
		Sleep(500);
		_iAni = 0;
		_GameState = 2;
	}
	//// 너구리 죽음 	
	if (_Rac.state == 11) {
		PlaySound(NULL, AfxGetInstanceHandle(), 0);
		PlaySound(MAKEINTRESOURCE(IDR_RAC_DIE), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		Sleep(1500);
		if (_iLive == 0) { // 마지막 너구리가 죽으면 
			Init();
			_GameState = 3;	//gameover
		}
		else {
			_iLive--;
			Init();
			LoadMap();
		}
	}


	//// 남은 시간	
	//// 너구리가 떨어지거나 죽으면 시간은 멈춘다.
	if (_iAni % 5 == 0 && _Rac.state != 10 && _Rac.state != 11) {
		_iTime--;
		if (_iTime == 0)
			_Rac.state = 10;	//너구리 죽음 		
	}

	//// 맵(처음 시작 할때 맵 전체를 한번 그린다.)
	if (_iAni == 1){
		objectdc.SelectObject(&_hMap);
		memdc.BitBlt(0, 0, rect.Width(), rect.Height(), &objectdc, 0, 0, SRCCOPY);
		//DrawBitmap(hMemDC, 0, 0, _hMap, FALSE);
	}

	else {
		//너구리 주위  
		objectdc.SelectObject(&_hMap);
		memdc.BitBlt(_Rac.x - 5, _Rac.y - 5, 60, 60, &objectdc, _Rac.x - 5, _Rac.y - 5, SRCCOPY);
//		DrawBitmap(hMemDC, _Rac.x - 5, _Rac.y - 5, _hMap, FALSE, _Rac.x - 5, _Rac.y - 5, _Rac.x + 55, _Rac.y + 55);
		//적 주위 
		for (i = 0; i < _EnemyCount; i++)
		{
			objectdc.SelectObject(&_hMap);
			memdc.BitBlt(_Ene[i].x - 2, _Ene[i].y + 5, 54, 53, &objectdc, _Ene[i].x - 2, _Ene[i].y + 5, SRCCOPY);
			//DrawBitmap(hMemDC, _Ene[i].x - 2, _Ene[i].y + 5, _hMap, FALSE, _Ene[i].x - 2, _Ene[i].y + 5, _Ene[i].x + 52, _Ene[i].y + 48);
		}
	}


	//// 점수 표시 (이전과 변화가 있을 때만 그린다.)
	//static int Score;
	//if (_iScore != Score || _iAni == 1){
	//	memdc.BitBlt(20, 50, 86, 25, &objectdc, 20, 50, SRCCOPY);
	//	//DrawBitmap(hMemDC, 20, 50, _hMap, FALSE, 20, 50, 106, 75);
	//	DrawDigit(memdc, 25, 50, _iScore, _hDigit, 7);
	//	Score = _iScore;
	//} 

	static int Score;
	if (_iScore != Score || _iAni == 1){
		objectdc.SelectObject(&_hMap);
		memdc.BitBlt(200, 50, 100, 25, &objectdc, 200, 50, SRCCOPY);
		//DrawBitmap(hMemDC, 200, 50, _hMap, FALSE, 200, 50, 300, 75);
		DrawDigit(memdc, 205, 50, _iScore, _hDigit, 7);
		Score = _iScore;
	}

	//너구리 위치
	//memdc.BitBlt(300, 50, 120, 25, &objectdc, 300, 50, SRCCOPY);
	//DrawBitmap(hMemDC, 300, 50, _hMap, FALSE, 300, 50, 420, 75);
	//DrawDigit(memdc, 305, 50, _Rac.x, _hDigit, 7);
	//DrawDigit(memdc, 360, 50, _Rac.y, _hDigit, 7);

	// 시간 바 표시 
	if (_iAni % 50 == 0 || _iAni == 1) {
		objectdc.SelectObject(&_hMap);
		memdc.BitBlt(600 - _iTime, 25, 50, 25, &objectdc, 200, 0, SRCCOPY);
		//DrawBitmap(hMemDC, 600 - _iTime, 25, _hMap, FALSE, 200, 0, 250, 25);
		memdc.Rectangle(650 - _iTime, 25, 650, 50);
		//Rectangle(hMemDC, 650 - _iTime, 25, 650, 50);
	}
	
	//먹은 과일 수 (이전과 변화가 있을 때만 그린다.)
	static char Eat;
	if (_iEat != Eat) {
		for (i = 0; i < _iEat; i++)
		{
			BITMAP info;
			_hFruit[_iLevel - 1].GetBitmap(&info);
			objectdc.SelectObject(&_hFruit[_iLevel - 1]);
			memdc.BitBlt(750, 490 - (i * 55), info.bmWidth, info.bmHeight, &objectdc, 0, 0, SRCCOPY);
			//DrawBitmap(hMemDC, 750, 490 - (i * 55), _hFruit[_iLevel - 1], FALSE);
		}
		Eat = _iEat;
	}

	// TODO : 오류
	// 항아리 & 과일 표시 
	for (i = 0; i < 12; i++) {
		//항아리 
		if (_Item[i].ch == 'M' || _Item[i].ch == 'N' || _Item[i].ch == 'O')
		{
			objectdc.SelectObject(&_hPot);
			BITMAP info;
			_hPot.GetBitmap(&info);
			memdc.BitBlt(_Item[i].x, _Item[i].y, info.bmWidth, info.bmHeight, &objectdc, 0, 0, SRCCOPY);
			//DrawBitmap(hMemDC, _Item[i].x, _Item[i].y, _hPot, FALSE);
		}

		//과일 
		else if (_Item[i].ch >= 'Q')
		{
			objectdc.SelectObject(&_hFruit[_iLevel - 1]);
			BITMAP info;
			_hFruit[_iLevel - 1].GetBitmap(&info);
			memdc.BitBlt(_Item[i].x, _Item[i].y, info.bmWidth, info.bmHeight, &objectdc, 0, 0, SRCCOPY);
			//DrawBitmap(hMemDC, _Item[i].x, _Item[i].y, _hFruit[_iLevel - 1], FALSE);
		}

		//너구리가 먹은 것에 대한 점수 표시 
		//너구리가 먹으면 *로 대치하고 점수를 표시한다음에 .로 바꿈

		else if (_Item[i].ch == '*') {
			//과일 지우고 점수 표시 

			if (_ScoreShow == 0)
			{
				objectdc.SelectObject(&_hMap);
				memdc.BitBlt(_Item[i].x, _Item[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY);
				//DrawBitmap(hMemDC, _Item[i].x, _Item[i].y, _hMap, FALSE, 200, 0, 250, 50);
			}

			DrawDigit(memdc, _Item[i].x, _Item[i].y + 25, _iItemScoreRate, _hDigit_sm);

			//점수를 10프레임 동안 보여짐 			
			if (++_ScoreShow == 11) {
				objectdc.SelectObject(&_hMap);
				memdc.BitBlt(_Item[i].x, _Item[i].y + 25, 40, 14, &objectdc, 200, 0, SRCCOPY);
				//DrawBitmap(hMemDC, _Item[i].x, _Item[i].y + 25, _hMap, FALSE, 200, 0, 240, 14);
				_Item[i].ch = '.';
				_ScoreShow = 0;
			}
		}
		else if (_Item[i].ch == '#') {
			objectdc.SelectObject(&_hMap);
			memdc.BitBlt(_Item[i].x, _Item[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY);
			//DrawBitmap(hMemDC, _Item[i].x, _Item[i].y, _hMap, FALSE, 200, 0, 250, 50);
			_Item[i].ch = '.';
		}
	}
	
	//적 표시 
	//뱀과 일반적인 적을 따로 그리는 이유는 투명 효과(Alpha) 때문에.	

	for (i = 0; i <_EnemyCount; i++) {

		//뱀
		if (_Ene[i].type == FALSE) {

			//너구리가 살아있고 (너구리가 죽으면 화면이 멈춰야 되므로)
			//알파 값이 255가 되면 뱀은 움직인다.
			if (_Rac.state != 10 && _Rac.state != 11 && _Ene[i].alpha == 255) _Ene[i].x += _Ene[i].speed;

			if (_Ene[i].x <= 30) {	//왼쪽 끝
				_Ene[i].x = 30;
				_Ene[i].speed *= -1;
				_Ene[i].state = !_Ene[i].state;
			}
			else if (_Ene[i].x >= 670) { //오른쪽 끝
				_Ene[i].x = 670;
				_Ene[i].speed *= -1;
				_Ene[i].state = !_Ene[i].state;
			}

			if (_Ene[i].state == FALSE) //방향(오른쪽을 보고 있을때)
				if (_Ene[i].alpha != 255) {
					_Ene[i].alpha += 5;	//선명하게
					objectdc.SelectObject(&_hMap);
					memdc.BitBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY); //검은색으로 기존의 것을 지우기 (200,0 ~ 250,50은 검정색)
					//DrawBitmap(hMemDC, _Ene[i].x, _Ene[i].y, _hMap, FALSE, 200, 0, 250, 50);

					BLENDFUNCTION bf;
					bf.BlendOp = AC_SRC_OVER;
					bf.BlendFlags = 0;
					bf.SourceConstantAlpha = _Ene[i].alpha;
					bf.AlphaFormat = 0;

					objectdc.SelectObject(&_hSnakeRight);

					BITMAP info;
					_hSnakeRight.GetBitmap(&info);
					memdc.AlphaBlend(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, bf);
					//DrawBitmapAlpha(hMemDC, _Ene[i].x, _Ene[i].y, _hSnakeRight, _Ene[i].alpha, (_iAni / 5 % 2) * 50, 0, (_iAni / 5 % 2 + 1) * 50, 50);
				}
				else
				{
					objectdc.SelectObject(&_hSnakeRight);
					BITMAP info;
					_hSnakeRight.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
					//DrawBitmap(hMemDC, _Ene[i].x, _Ene[i].y, _hSnakeRight, TRUE, (_iAni / 5 % 2) * 50, 0, (_iAni / 5 % 2 + 1) * 50, 50);
				}
			else if (_Ene[i].alpha != 255) {
				_Ene[i].alpha += 5;	//선명하게  
				objectdc.SelectObject(&_hMap);
				memdc.BitBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY); //검은색으로 기존의 것을 지우기 (200,0 ~ 250,50은 검정색)
				//DrawBitmap(hMemDC, _Ene[i].x, _Ene[i].y, _hMap, FALSE, 200, 0, 250, 50);

				BLENDFUNCTION bf;
				bf.BlendOp = AC_SRC_OVER;
				bf.BlendFlags = 0;
				bf.SourceConstantAlpha = _Ene[i].alpha;
				bf.AlphaFormat = 0;

				objectdc.SelectObject(&_hSnakeLeft);

				BITMAP info;
				_hSnakeLeft.GetBitmap(&info);
				memdc.AlphaBlend(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, bf);
				//DrawBitmapAlpha(hMemDC, _Ene[i].x, _Ene[i].y, _hSnakeLeft, _Ene[i].alpha, (_iAni / 5 % 2) * 50, 0, (_iAni / 5 % 2 + 1) * 50, 50);
			}

			else // 방향(왼쪽을 보고 있을때)
			{
				objectdc.SelectObject(&_hSnakeLeft);
				BITMAP info;
				_hSnakeLeft.GetBitmap(&info);
				memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				//DrawBitmap(hMemDC, _Ene[i].x, _Ene[i].y, _hSnakeLeft, TRUE, (_iAni / 5 % 2) * 50, 0, (_iAni / 5 % 2 + 1) * 50, 50);
			}
		}
	}



	//일반적인 적 
	for (i = 0; i < _EnemyCount; i++) {

		if (_Ene[i].type == TRUE) {

			if (_Rac.state != 10 && _Rac.state != 11) _Ene[i].x += _Ene[i].speed;

			if (_Ene[i].x <= 30) {
				_Ene[i].x = 30;
				_Ene[i].speed *= -1;
				_Ene[i].state = !_Ene[i].state;
			}
			else if (_Ene[i].x >= 670) {
				_Ene[i].x = 670;
				_Ene[i].speed *= -1;
				_Ene[i].state = !_Ene[i].state;
			}

			if (_Ene[i].speed == 4 || _Ene[i].speed == -4) { // 속도가 4인 적은 빨간색, 나머지는 초록색 
				if (_Ene[i].state == FALSE) //방향
				{
					objectdc.SelectObject(&_hEnemyRightRed);
					BITMAP info;
					_hEnemyRightRed.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth/2, info.bmHeight, RGB(0, 0, 0));
					//DrawBitmap(hMemDC, _Ene[i].x, _Ene[i].y, _hEnemyRightRed, TRUE, (_iAni % 2) * 50, 0, (_iAni % 2 + 1) * 50, 50);
				}
					
				else
				{
					objectdc.SelectObject(&_hEnemyLeftRed);
					BITMAP info;
					_hEnemyLeftRed.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth/2, info.bmHeight, RGB(0, 0, 0));
					//DrawBitmap(hMemDC, _Ene[i].x, _Ene[i].y, _hEnemyLeftRed, TRUE, (_iAni % 2) * 50, 0, (_iAni % 2 + 1) * 50, 50);
				}
			}
			else {
				if (_Ene[i].state == FALSE) //방향
				{
					objectdc.SelectObject(&_hEnemyRight);
					BITMAP info;
					_hEnemyRight.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth/2, info.bmHeight, RGB(0, 0, 0));
					//DrawBitmap(hMemDC, _Ene[i].x, _Ene[i].y, _hEnemyRight, TRUE, (_iAni % 2) * 50, 0, (_iAni % 2 + 1) * 50, 50);
				}
				else
				{
					objectdc.SelectObject(&_hEnemyLeft);
					BITMAP info;
					_hEnemyLeft.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth/2, info.bmHeight, RGB(0, 0, 0));
					//DrawBitmap(hMemDC, _Ene[i].x, _Ene[i].y, _hEnemyLeft, TRUE, (_iAni % 2) * 50, 0, (_iAni % 2 + 1) * 50, 50);
				}
			}
		}
	}

	////적 충돌 감지 
	CheckCollision_Enemy();

	////너구리 
	switch (_Rac.state) {
	case 1:
		objectdc.SelectObject(&_hStand);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));
		//DrawBitmap(hMemDC, _Rac.x, _Rac.y, _hStand, TRUE, 0, 0, 50, 50);
		break;

	case 2:
		objectdc.SelectObject(&_hLeft);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, _Rac.step * 50, 0, 50, 50, RGB(0, 0, 0));
		//DrawBitmap(hMemDC, _Rac.x, _Rac.y, _hLeft, TRUE, _Rac.step * 50, 0, (_Rac.step + 1) * 50, 50);
		break;

	case 3:
		objectdc.SelectObject(&_hRight);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, _Rac.step * 50, 0, 50, 50, RGB(0, 0, 0));
		//DrawBitmap(hMemDC, _Rac.x, _Rac.y, _hRight, TRUE, _Rac.step * 50, 0, (_Rac.step + 1) * 50, 50);
		break;

	case 4:
		objectdc.SelectObject(&_hUpDown);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, _Rac.step * 50, 0, 50, 50, RGB(0, 0, 0));
		//DrawBitmap(hMemDC, _Rac.x, _Rac.y, _hUpDown, TRUE, _Rac.step * 50, 0, (_Rac.step + 1) * 50, 50);
		break;

	case 5:
		// 점프 패턴을 읽어 와서 그림 
		_Rac.x += _StandJump[_JumpFrame].x;
		_Rac.y += _StandJump[_JumpFrame].y;

		objectdc.SelectObject(&_hStand);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_StandJump[_JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));
		//DrawBitmap(hMemDC, _Rac.x, _Rac.y, _hStand, TRUE, (_StandJump[_JumpFrame].frame) * 50, 0,
		//	(_StandJump[_JumpFrame].frame + 1) * 50, 50);

		_JumpFrame++;

		if (_JumpFrame == 10) {
			_JumpFrame = 0;	//초기화 
			_Rac.state = 1;	//착지 하면 다시 1상태로 
		}
		break;
		
	case 6:
		//화면 왼쪽 끝이므로 화면 밖으로 안나가게 
		if (_Rac.x >= 30)
			_Rac.x += _LeftShortJump[_JumpFrame].x;
		_Rac.y += _LeftShortJump[_JumpFrame].y;

		objectdc.SelectObject(&_hLeftJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_LeftShortJump[_JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));

		//DrawBitmap(hMemDC, _Rac.x, _Rac.y, _hLeftJump, TRUE, (_LeftShortJump[_JumpFrame].frame) * 50, 0,
		//	(_LeftShortJump[_JumpFrame].frame + 1) * 50, 50);

		_JumpFrame++;

		if (_JumpFrame == 11) {
			_JumpFrame = 0;
			_Rac.state = 2;
			//충돌 검사 
			//이 프로그램은 화살표키로 움직일때 충동 검사를 (압정, 낭떠러지)한다.
			//문제는 너구리가 점프를 끝내고 바닥에 착지 하면 
			//방향키를 안눌렀기 때문에 충돌 검사가 안된다.
			//따라서 착지하면 충돌검사를 한다.
			CheckCollision();
		}

		break;

	case 7:
		//화면 왼쪽 끝이므로 화면 밖으로 안나가게 
		if (_Rac.x >= 30)
			_Rac.x += _LeftLongJump[_JumpFrame].x;
		_Rac.y += _LeftLongJump[_JumpFrame].y;

		objectdc.SelectObject(&_hLeftJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_LeftLongJump[_JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));

		//DrawBitmap(hMemDC, _Rac.x, _Rac.y, _hLeftJump, TRUE, (_LeftLongJump[_JumpFrame].frame) * 50, 0,
		//	(_LeftLongJump[_JumpFrame].frame + 1) * 50, 50);

		_JumpFrame++;

		if (_JumpFrame == 17) {
			_JumpFrame = 0;
			_Rac.state = 2;
			//충돌 검사 
			//이 프로그램은 화살표키로 움직일때 충동 검사를 (압정, 낭떠러지)한다.
			//문제는 너구리가 점프를 끝내고 바닥에 착지 하면 
			//방향키를 안눌렀기 때문에 충돌 검사가 안된다.
			//따라서 착지하면 충돌검사를 한다.
			CheckCollision();
		}
		break;

	case 8:
		//오른쪽 경계면 
		//1층은 y좌표 775, 2층이상은 y좌표 670 
		if (_Rac.x <= 670 || (_Rac.x <= 775 && _Rac.y >= 530))
			_Rac.x -= _LeftShortJump[_JumpFrame].x;
		_Rac.y += _LeftShortJump[_JumpFrame].y;

		objectdc.SelectObject(&_hRightJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_LeftShortJump[_JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));

		//DrawBitmap(hMemDC, _Rac.x, _Rac.y, _hRightJump, TRUE, (_LeftShortJump[_JumpFrame].frame) * 50, 0,
		//	(_LeftShortJump[_JumpFrame].frame + 1) * 50, 50);

		_JumpFrame++;

		if (_JumpFrame == 11) {
			_JumpFrame = 0;
			_Rac.state = 3;
			//충돌 검사 
			//이 프로그램은 화살표키로 움직일때 충동 검사를 (압정, 낭떠러지)한다.
			//문제는 너구리가 점프를 끝내고 바닥에 착지 하면 
			//방향키를 안눌렀기 때문에 충돌 검사가 안된다.
			//따라서 착지하면 충돌검사를 한다.
			CheckCollision();

		}

		break;

	case 9:
		//오른쪽 경계면 
		//1층은 y좌표 775, 2층이상은 y좌표 670 
		if (_Rac.x <= 670 || (_Rac.x <= 775 && _Rac.y >= 530))
			_Rac.x -= _LeftLongJump[_JumpFrame].x;
		_Rac.y += _LeftLongJump[_JumpFrame].y;

		objectdc.SelectObject(&_hRightJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_LeftLongJump[_JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));

		//DrawBitmap(hMemDC, _Rac.x, _Rac.y, _hRightJump, TRUE, (_LeftLongJump[_JumpFrame].frame) * 50, 0,
		//	(_LeftLongJump[_JumpFrame].frame + 1) * 50, 50);

		_JumpFrame++;

		if (_JumpFrame == 17) {
			_JumpFrame = 0;
			_Rac.state = 3;
			//충돌 검사 
			//이 프로그램은 화살표키로 움직일때 충동 검사를 (압정, 낭떠러지)한다.
			//문제는 너구리가 점프를 끝내고 바닥에 착지 하면 
			//방향키를 안눌렀기 때문에 충돌 검사가 안된다.
			//따라서 착지하면 충돌검사를 한다.
			CheckCollision();
		}

		break;

	case 10: //떨어지는 너구리  
		if (_bIsDrop_Sound == FALSE) {
			//PlaySound(NULL, _hInstance, 0);
			//PlaySound(MAKEINTRESOURCE(IDR_RAC_DROP), _hInstance, SND_RESOURCE | SND_ASYNC);
			_bIsDrop_Sound = TRUE;
		}

		if (_Rac.y >= 578) {
			_Rac.y = 578;
			//다 떨어진 상태
			
			objectdc.SelectObject(&_hDie);
			memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));

			//DrawBitmap(hMemDC, _Rac.x, _Rac.y, _hDie, TRUE);
			_Rac.state = 11;
		}
		else {
			_Rac.y += 5;
			//덜 떨어진 상태 
			
			objectdc.SelectObject(&_hDrop);
			memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_iAni / 2 % 6) * 50, 0, 50, 50, RGB(0, 0, 0));
			//DrawBitmap(hMemDC, _Rac.x, _Rac.y, _hDrop, TRUE, (_iAni / 2 % 6) * 50, 0,
			//	(_iAni / 2 % 6 + 1) * 50, 50);
		}
		break;
		
	case 11: //너구리 떨어진 상태 				
		break;

	}

	//SelectObject(hMemDC, OldBrush);
	//SelectObject(hMemDC, OldPen);
	//SelectObject(hMemDC, OldBit);
	//DeleteObject(MyBrush);
	//DeleteObject(MyPen);
	//DeleteDC(hMemDC);
	//ReleaseDC(_pGame->GetWindow(), hdc);
	//InvalidateRect(_pGame->GetWindow(), NULL, FALSE);
	Invalidate(FALSE);
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	memdc.SelectObject(&_cBit);

	CRect rect;
	GetClientRect(&rect);

	switch (_GameState) {
	case 0:
		// 171은 너구리가 자리를 다 잡고 춤추기 시작하는 시점 
		if (_bIsDrawAll == TRUE || _iAni == 1 || _iAni == 171)
			dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memdc, 0, 0, SRCCOPY);
		else
			dc.BitBlt(120, 430, 780, 70, &memdc, 120, 430, SRCCOPY);
		break;

	case 1:
		// 처음에는 전부 다 그리고 그 이후는 이전과 비교해서 변화는 부분만 다시 그린다.
		// 속도 향상을 위해 매번 전부 다시 그리지 않음 
		// 처음에 매번 화면 전체를 다시 그리게 만들었는데(구현 하기 쉬움)
		// 펜티엄200에서 테스트 결과 속도가 엄청나게 느림 
		// 그래서 변하는 부분만 다시 그리게 수정 했음 
		// 그래서 게임에서 화면을 그리는 부분이 조금 복잡해짐 
		if (_bIsDrawAll == TRUE || _iAni == 1)
			dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memdc, 0, 0, SRCCOPY);
		else {

			//점수
			dc.BitBlt(25, 50, 100, 25, &memdc, 25, 50, SRCCOPY);

			//시간 
			dc.BitBlt(150, 25, 500, 25, &memdc, 150, 25, SRCCOPY);

			//먹은과일 
			dc.BitBlt(750, 110, 50, 440, &memdc, 750, 110, SRCCOPY);

			//너구리 주위 
			dc.BitBlt(_Rac.x - 10, _Rac.y - 10, 70, 70, &memdc, _Rac.x - 10, _Rac.y - 10, SRCCOPY);

			//적 주위 
			for (int i = 0; i <_EnemyCount; i++)
				dc.BitBlt(_Ene[i].x - 2, _Ene[i].y + 5, 60, 50, &memdc, _Ene[i].x - 2, _Ene[i].y + 5, SRCCOPY);

			//아이템 주위 
			for (int i = 0; i < 12; i++)
				dc.BitBlt(_Item[i].x, _Item[i].y, 50, 50, &memdc, _Item[i].x, _Item[i].y, SRCCOPY);
		}
		break;

	case 2:
		if (_bIsDrawAll == TRUE || _iAni == 1)
			dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memdc, 0, 0, SRCCOPY);
		else
			dc.BitBlt(500, 400, 550, 450, &memdc, 500, 400, SRCCOPY);
		break;

	case 3:
		if (_bIsDrawAll == TRUE || _iAni == 1)
			dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memdc, 0, 0, SRCCOPY);
		else {
			//'GAME OVER'
			dc.BitBlt(0, 200, 900, 75, &memdc, 0, 200, SRCCOPY);

			//떨어지는 너구리 
			dc.BitBlt(430, 0, 50, 590, &memdc, 430, 0, SRCCOPY);
		}
		break;
	}

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

void CChildView::GameCycle()
{
	switch (_GameState) {
	case 0:
		_bIsDrawAll = FALSE;
		GameIntro();
		break;

	case 1:
		_bIsDrawAll = FALSE;
		GamePlay();
		break;

	case 2:
		_bIsDrawAll = FALSE;
		GameClear();
		break;

	case 3:
		_bIsDrawAll = FALSE;
		GameOver();
		break;
	}
}


//void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	switch (_GameState)
//	{
//	case 0:
//		if (nChar == VK_SPACE){
//			//음악 종료 함수 호출 
//
//			//초기화 작업.
//			_iLevel = 1;
//			_iLive = LIVE;
//			_iScore = 0;
//			Init();
//			LoadMap();
//			_GameState = 1;
//			//스페이스를 조금 길게 누르면 게임이 시작하자 마자 너구리가 점프하므로 
//			//이를 방지 하기 위해 
//			Sleep(100);
//		}
//		break;
//
//		//게임 플레이 도중
//	case 1:
//		//너구리 상태(_Rac.state)에 대해 switch 문 작성. 오토마다 그림 참고.
//		switch (_Rac.state) {
//		case 1:
//			if (nChar == VK_LEFT)
//				_Rac.state = 2;
//
//			else if (nChar == VK_RIGHT)
//				_Rac.state = 3;
//
//			// 'F'는 사다리,  +20 한 것은 너구리의 중심을 맞추기 위해 
//			else if (nChar == VK_UP) {
//				if (_cMap[(_Rac.y) / 25][(_Rac.x + 20) / 25] == 'F')
//					_Rac.state = 4;
//			}
//			else if (nChar == VK_DOWN) {
//				if (_cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F')
//					_Rac.state = 4;
//			}
//			else if (nChar == VK_SPACE) {
//				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
//				_Rac.state = 5;
//			}
//
//			break;
//
//		case 2:
//			if (nChar == VK_LEFT) {
//				if (_Rac.x >= 25) {
//					_Rac.x -= _Rac.speedx;
//					_Rac.step = !_Rac.step;
//					if (_Rac.x % 20 == 0)
//						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
//					CheckCollision();
//				} //키 버퍼 
//				if (nChar == VK_SPACE) {
//					PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
//					_Rac.state = 7;
//				}
//			}
//			else if (nChar == VK_RIGHT)
//				_Rac.state = 3;
//
//			else if (nChar == VK_UP) {
//				if (_cMap[(_Rac.y - 25) / 25][(_Rac.x + 20) / 25] == 'F')
//					_Rac.state = 4;
//			}
//			else if (nChar == VK_DOWN) {
//				if (_cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F')
//					_Rac.state = 4;
//			}
//			else if (nChar == VK_SPACE) {
//				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
//				_Rac.state = 6;
//			}
//
//			break;
//
//		case 3:
//			if (nChar == VK_LEFT)
//				_Rac.state = 2;
//
//			else if (nChar == VK_RIGHT) {
//				if ((_Rac.x <= 670) || (_Rac.x <= 775 && _Rac.y == 578)) {
//					_Rac.x += _Rac.speedx;
//					_Rac.step = !_Rac.step;
//					if (_Rac.x % 20 == 0)
//						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
//					CheckCollision();
//				} // 키 버퍼 
//				if (nChar == VK_SPACE)  {
//					PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
//					_Rac.state = 9;
//				}
//			}
//			else if (nChar == VK_UP) {
//				if (_cMap[(_Rac.y - 25) / 25][(_Rac.x + 20) / 25] == 'F')
//					_Rac.state = 4;
//			}
//			else if (nChar == VK_DOWN) {
//				if (_cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F')
//					_Rac.state = 4;
//			}
//			else if (nChar == VK_SPACE) {
//				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
//				_Rac.state = 8;
//			}
//
//			break;
//
//		case 4:
//			if (nChar == VK_UP)
//				if (_cMap[(_Rac.y + 20) / 25][(_Rac.x + 20) / 25] == 'F') {
//					_Rac.y -= _Rac.speedy;
//					_Rac.step = !_Rac.step;
//					if ((_Rac.y - 3) % 20 == 0)
//						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
//				}
//				else
//					_Rac.state = 1;
//
//			else if (nChar == VK_DOWN)
//				if (_cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F') {
//					_Rac.y += _Rac.speedy;
//					_Rac.step = !_Rac.step;
//					if ((_Rac.y - 3) % 20 == 0)
//						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
//				}
//				else
//					_Rac.state = 1;
//			break;
//		}
//		break;
//
//		
//	//레벨 클리어 ( 내용 없음 )
//	case 2:
//		break;
//
//	//Game Over
//	case 3:
//		if (nChar == VK_SPACE){
//			//음악 종료 함수 호출
//
//			//초기화 작업.
//			 _iAni = 0;
//			_GameState = 0;
//			Sleep(100);
//			Invalidate(false);
//		}
//		break;
//	}
//	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
//}

void CChildView::LoadMap()
{
	CClientDC dc(this);
	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	GetClientRect(&rect);

	HRSRC hRSrc = FindResource(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAP), _T("TEXT"));
	DWORD size = SizeofResource(AfxGetInstanceHandle(), hRSrc);
	HGLOBAL hMem = LoadResource(AfxGetInstanceHandle(), hRSrc);
	PVOID ptr = LockResource(hMem);
	char *str = (char*)malloc(size + 1);
	memcpy(str, ptr, size);
	str[size] = 0;
	int m_index = 0;
	m_index += 913 * (_iLevel - 1) + 3;
	char ch;


	static int i, j;

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 35; j++){
			ch = str[m_index++];
			if (ch != '\n')
				_cMap[i][j] = ch;
		}
	}

	if (_hMap.m_hObject == NULL)
		_hMap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memdc.SelectObject(&_hMap);

	int index = 0;

	for (i = 0; i < 26; i++){
		for (j = 0; j < 33; j++){
			if (_cMap[i][j] >= 'A' && _cMap[i][j] <= 'F'){
				objectdc.SelectObject(_hMapEle[_cMap[i][j] - 65]);
				memdc.TransparentBlt(j * 25, i * 25, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
			}
			else if (_cMap[i][j] >= 'G' && _cMap[i][j] <= 'L'){
				_Ene[_EnemyCount].x = j * 25;
				_Ene[_EnemyCount].y = i * 25 - 25;
				_Ene[_EnemyCount].type = TRUE;
				_Ene[_EnemyCount].state = (_cMap[i][j] - 'G') % 2;
				_Ene[_EnemyCount].alpha = 255;
				if (_Ene[_EnemyCount].state)
					_Ene[_EnemyCount].speed = (2 + (_cMap[i][j] - 'G') / 2)* (-1);
				else
					_Ene[_EnemyCount].speed = 2 + (_cMap[i][j] - 'G') / 2;
				_EnemyCount++;
			}
			else if (_cMap[i][j] >= 'M'){
				_Item[index].x = j * 25;
				_Item[index].y = i * 25 - 26;
				_Item[index].ch = _cMap[i][j];
				index++;
			}
		}
	}
	
	// 과일 (게임 상단에 현재 레벨을 알수 있는 과일들)
	// 당근 , 앵두 ... 
	for (i = 0; i < _iLevel; i++)
	{
		objectdc.SelectObject(&_hFruit[i]);
		memdc.TransparentBlt((670 - (_iLevel - 1) * 55) + i * 55, 70, 51, 51, &objectdc, 0, 0, 51, 51, RGB(0, 0, 0));
	}
	

	// 'SCORE'
	objectdc.SelectObject(&_hScore);
	memdc.TransparentBlt(25, 25, 75, 23, &objectdc, 0, 0, 75, 23, RGB(0, 0, 0));

	// 남은 너구리 수
	for (i = 0; i < _iLive; i++)
	{
		objectdc.SelectObject(&_hStand);
		memdc.BitBlt(840, 600 - (i * 55), 50, 50, &objectdc, 0, 0, SRCCOPY);
	}

	free(str);
}

void CChildView::CheckCollision()
{
	static int x1, y1, x2, y2;
	static int xx1, yy1, xx2, yy2;

	if (_Rac.state == 2 || _Rac.state == 6 || _Rac.state == 7){
		x1 = _Rac.x + 10;
		y1 = _Rac.y + 5;
		x2 = _Rac.x + 30;
		y2 = _Rac.y + 45;
	}
	else{
		x1 = _Rac.x + 20;
		y1 = _Rac.y + 5;
		x2 = _Rac.x + 40;
		y2 = _Rac.y + 40;
	}

	if (_Rac.state == 2 || _Rac.state == 3){
		if (_cMap[y2 / 25][x1 / 25] == 'E' || _cMap[y2 / 25 + 1][x1 / 25] == '.'){
			xx1 = (x1 / 25 * 25) + 5;
			xx2 = ((x1 / 25 + 1) * 25) - 5;
			if ((xx1 > x1 && xx1 <x2) || (xx2 > x1 && xx2 < x2)){
				_Rac.state = 10;
				return;
			}
		}
		if (_cMap[y2 / 25][x2 / 25] == 'E' || _cMap[y2 / 25 + 1][x2 / 25] == '.') {
			xx1 = (x2 / 25 * 25) + 5;
			xx2 = ((x2 / 25 + 1) * 25) - 5;
			if ((xx1 > x1 && xx1 < x2) || (xx2 > x1 && xx2 < x2)) {
				_Rac.state = 10;
				return;
			}
		}
	}

	//과일, 항아리 충돌 검사
	char i;

	for (i = 0; i < 12; i++){
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

				if (_Item[i].ch >= 'Q') _iEat++;

				if (_Item[i].ch == 'N' || _Item[i].ch == 'M'){
					PlaySound(MAKEINTRESOURCE(IDR_SNAKE), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

					_Ene[_EnemyCount].x = _Item[i].x;
					_Ene[_EnemyCount].y = _Item[i].y;
					_Ene[_EnemyCount].type = FALSE;
					_Ene[_EnemyCount].alpha = 10;

					if (_Item[i].ch == 'N') {
						_Ene[_EnemyCount].state = TRUE;
						_Ene[_EnemyCount].speed = -1;

					}
					else {
						_Ene[_EnemyCount].state = FALSE;
						_Ene[_EnemyCount].speed = 1;
					}

					_Item[i].ch = '.';
					_EnemyCount++;
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

void CChildView::CheckCollision_Enemy()
{
	static int x1, y1, x2, y2;
	static int xx1, yy1, xx2, yy2;

	if (_Rac.state == 2 || _Rac.state == 6 || _Rac.state == 7){
		x1 = _Rac.x + 10;
		y1 = _Rac.y + 5;
		x2 = _Rac.x + 30;
		y2 = _Rac.y + 45;
	}
	else if (_Rac.state == 3 || _Rac.state == 8 || _Rac.state == 9){
		x1 = _Rac.x + 20;
		y1 = _Rac.y + 5;
		x2 = _Rac.x + 40;
		y2 = _Rac.y + 45;
	}
	else{
		x1 = _Rac.x + 5;
		y1 = _Rac.y + 5;
		x2 = _Rac.x + 40;
		y2 = _Rac.y + 45;
	}

	char i;

	for (i = 0; i < _EnemyCount; i++){
		if (_Ene[i].alpha == 255){
			xx1 = _Ene[i].x + 7;
			yy1 = _Ene[i].y + 5;
			xx2 = _Ene[i].x + 43;
			yy2 = _Ene[i].y + 50;

			if ((x1 > xx1 && x1 < xx2 && y1 > yy1 && y1 < yy2) ||
				(x1 > xx1 && x1 < xx2 && y2 > yy1 && y2 < yy2) ||
				(x2 > xx1 && x2 < xx2 && y1 > yy1 && y2 < yy2) ||
				(x2 > xx1 && x2 < xx2 && y2 > yy1 && y2 < yy2))
				_Rac.state = 10;
			
		}
	}
}


void CChildView::GameClear()
{

}


void CChildView::GameOver()
{
	//CClientDC dc(this);

	//CDC memdc;
	//memdc.CreateCompatibleDC(&dc);

	//CRect rect;
	//GetClientRect(&rect);

	//CBitmap bmp;
	//bmp.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());

	//CDC game_overdc;
	//game_overdc.CreateCompatibleDC(&memdc);


	//CDC dead_racoondc;
	//dead_racoondc.CreateCompatibleDC(&memdc);
	//
	//game_overdc.SelectObject(&_gameover);
	//dead_racoondc.SelectObject(&_)

	////바닥 그리기 
	//memdc.Rectangle(0, 585, 900, 670);

	//static int i, j;
	//j = 0;
	//for (i = 585; i < 670; i += j) {
	//	j++;
	//	/*MoveToEx(hMemDC, 0, i, NULL);
	//	LineTo(hMemDC, 900, i);*/
	//	memdc.MoveTo(0, i);
	//	memdc.LineTo(900, i);
	//}

	
	

}


void CChildView::Init()
{
	//초기화
	_Rac.state = 1;			//너구리는 정면을 보고 있다 
	_Rac.x = 775;			//너구리의 시작 위치 
	_Rac.y = 578;			//너구리의 시작 위치 
	_Rac.speedx = 5;		//너구리 이동 속도 
	_Rac.speedy = 5;		//너구리 이동 속도 
	_iTime = 500;			//게임 제한 시간 
	_iItemScoreRate = 5;	//아이템 점수, 2배씩 곱해지면서 증가 
	_iEat = 0;				//먹은 과일수 
	_iAni = 0;				//애니메이션 효과를 위해 
	_bIsDrop_Sound = FALSE;	//너구리가 떨어질때 나는 소리 상태 

	_EnemyCount = 0;		//적의 숫자 

	_ScoreShow = 0;			//먹은 과일 점수 표시 시간 
	_JumpFrame = 0;			//점프를 보여 줄때 필요 (카운터)
}

void CChildView::DrawDigit(CDC& cDC, int x, int y, int score, CBitmap& cBit, int cipher, COLORREF crTransColor)
{
	CDC MemDC;
	CBitmap *OldBitmap;
	int bx, by;
	BITMAP bit;

	MemDC.CreateCompatibleDC(&cDC);
	OldBitmap = MemDC.SelectObject(&cBit);

	cBit.GetBitmap(&bit);
	bx = bit.bmWidth / 10;
	by = bit.bmHeight;

	int len;
	int blank = 0;
	char str[10];

	_itoa_s(score, str, 10);
	len = strlen(str);

	if (cipher)
		blank = cipher - len - 1;

	//숫자를 자리수를 고려하여 공백을 넣고 숫자 표시  
	for (int i = 0; i < len; i++)
		cDC.TransparentBlt(x + (blank*bx) + (i*bx), y, bx, by, &MemDC, bx*(str[i] - '0'), 0, bx, by, crTransColor);

	MemDC.SelectObject(&OldBitmap);
	MemDC.DeleteDC();
}

void CChildView::HandleKeys()
{
	switch (_GameState) {

		//인트로 화면 
	case 0:
		if (GetAsyncKeyState(JUMP) < 0) {
			//인트로 음악 종료 
			PlaySound(NULL, AfxGetInstanceHandle(), 0);
			// 초기화 
			_iLevel = 1;
			_iLive = LIVE;
			_iScore = 0;
			Init();
			LoadMap();
			_GameState = 1;
			//스페이스를 조금 길게 누르면 게임이 시작하자 마자 너구리가 점프하므로 
			//이를 방지 하기 위해 
			Sleep(100);
		}
		break;

		//게임중
		//키를 동시에 두개 누른것을 처리하기 위해서는 API만으로는 불가 
		//다이렉트엑스를 쓰던지 키 버퍼를 만들어야 함 
		//여기서는 키 버퍼 비슷하게 구현 
		//왼쪽 입력이 들어온 상태에서 점프입력이 들어오면 또는 
		//오른쪽 입력이 들어온 상태에서 점프입력이 들어오면 
		//다시 말해 현재 입력이 점프이고 그 이전 입력이 오른쪽이나 왼쪽이면
		//길게 점프 함 
		//별도의 버퍼 메모리 없이 키 버퍼 구현 

		/************************************************************
		*아래 소스는 오토마다 그림을 참고							*
		*************************************************************/

	case 1:
		switch (_Rac.state) {
		case 1:
			if (GetAsyncKeyState(LEFT) < 0)
				_Rac.state = 2;

			else if (GetAsyncKeyState(RIGHT) < 0)
				_Rac.state = 3;

			// 'F'는 사다리,  +20 한 것은 너구리의 중심을 맞추기 위해 
			else if (GetAsyncKeyState(UP) < 0) {
				if (_cMap[(_Rac.y) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(DOWN) < 0) {
				if (_cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(JUMP) < 0) {
				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				_Rac.state = 5;
			}

			break;

		case 2:
			if (GetAsyncKeyState(LEFT) < 0) {
				if (_Rac.x >= 25) {
					_Rac.x -= _Rac.speedx;
					_Rac.step = !_Rac.step;
					if (_Rac.x % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
					CheckCollision();
				} //키 버퍼 
				if (GetAsyncKeyState(JUMP) < 0) {
					PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					_Rac.state = 7;
				}
			}
			else if (GetAsyncKeyState(RIGHT) < 0)
				_Rac.state = 3;

			else if (GetAsyncKeyState(UP) < 0) {
				if (_cMap[(_Rac.y - 25) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(DOWN) < 0) {
				if (_cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(JUMP) < 0) {
				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				_Rac.state = 6;
			}

			break;

		case 3:
			if (GetAsyncKeyState(LEFT) < 0)
				_Rac.state = 2;

			else if (GetAsyncKeyState(RIGHT) < 0) {
				if ((_Rac.x <= 670) || (_Rac.x <= 775 && _Rac.y == 578)) {
					_Rac.x += _Rac.speedx;
					_Rac.step = !_Rac.step;
					if (_Rac.x % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
					CheckCollision();
				} // 키 버퍼 
				if (GetAsyncKeyState(JUMP) < 0)  {
					PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					_Rac.state = 9;
				}
			}
			else if (GetAsyncKeyState(UP) < 0) {
				if (_cMap[(_Rac.y - 25) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(DOWN) < 0) {
				if (_cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(JUMP) < 0) {
				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				_Rac.state = 8;
			}

			break;

		case 4:
			if (GetAsyncKeyState(UP) < 0)
				if (_cMap[(_Rac.y + 20) / 25][(_Rac.x + 20) / 25] == 'F') {
					_Rac.y -= _Rac.speedy;
					_Rac.step = !_Rac.step;
					if ((_Rac.y - 3) % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
				}
				else
					_Rac.state = 1;

			else if (GetAsyncKeyState(DOWN) < 0)
				if (_cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F') {
					_Rac.y += _Rac.speedy;
					_Rac.step = !_Rac.step;
					if ((_Rac.y - 3) % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
				}
				else
					_Rac.state = 1;

			break;
		}

		break;


		//레벨 클리어 
	case 2:
		break;

		//GAME OVER
	case 3:
		if (GetAsyncKeyState(JUMP) < 0) {
			PlaySound(NULL, AfxGetInstanceHandle(), 0);
			_iAni = 0;
			_GameState = 0;
			Sleep(100);
		}

	}

}
