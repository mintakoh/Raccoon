#include "stdafx.h"
#include "Game.h"
#include "resource.h"
#include "MainFrm.h"


CGame::CGame()
	: _bIsDrawAll(false)
	, _GameState(0)
	, _iAni(0)
	, _iLevel(1)
	, _ScoreShow(0)
	, _iTime(0)
	, _iScore(0)
	, _iItemScoreRate(0)
	, _bIsDrop_Sound(FALSE)
	, is_up(false)
{
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

	//아기
	_hBaby.LoadBitmapW(IDB_BABY);
}


CGame::~CGame()
{
}


void CGame::GameIntro()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView* pView = (CChildView*)pFrame->GetChildView();

	CClientDC dc(pView);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	//시간
	if (_iAni == 1000)
		_iAni = 0;
	else
		_iAni++;

	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	pView->GetClientRect(&rect);

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
		objectdc.SelectObject(_Rac._hLeft);

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
		objectdc.SelectObject(&_Rac._hStand);
		for (int i = 120; i <= 520; i += 100)
			memdc.TransparentBlt(i, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni < 250)
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, (1 - _iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));
		else
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni > 220 && _iAni < 255) {
			objectdc.SelectObject(_Rac._hSurprise);
			memdc.TransparentBlt(640, 435, 29, 21, &objectdc, 0, 0, 29, 21, RGB(0, 0, 0));
		}

		objectdc.SelectObject(_Rac._hStand);
		memdc.TransparentBlt(720, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));
	}
	else {
		objectdc.SelectObject(_Rac._hRight);
		for (int i = 120; i <= 520; i += 100)
			memdc.TransparentBlt(i, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));

		objectdc.SelectObject(_Rac._hStand);
		memdc.TransparentBlt(620, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));

		objectdc.SelectObject(_Rac._hSurprise);
		memdc.TransparentBlt(640, 435, 29, 21, &objectdc, 0, 0, 29, 21, RGB(0, 0, 0));

		objectdc.SelectObject(_Rac._hLeft);
		memdc.TransparentBlt(720, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));
	}

	if (_iAni == 171) {
		objectdc.SelectObject(_hLets);
		memdc.BitBlt(220, 120, 455, 218, &objectdc, 0, 0, SRCCOPY);

		PlaySound(MAKEINTRESOURCE(IDR_INTRO), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	}

	pView->Invalidate(false);
}

void CGame::GamePlay()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView* pView = (CChildView*)pFrame->GetChildView(); 
	
	pView->GetClientRect(&rect);
	CClientDC dc(pView);
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
	if (Item::_iEat == 8 && _ScoreShow == 1) {
		Sleep(500);
		_iAni = 0;
		_GameState = 2;
	}
	//// 너구리 죽음 	
	if (_Rac.state == 11) {
		PlaySound(NULL, AfxGetInstanceHandle(), 0);
		PlaySound(MAKEINTRESOURCE(IDR_RAC_DIE), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		Sleep(1500);
		if (Raccoon::_iLive == 0) { // 마지막 너구리가 죽으면 
			Init();
			_GameState = 3;	//gameover
		}
		else {
			Raccoon::_iLive--;
			Init();
			_Map.LoadMap(rect, _Ene, _Item, _Rac, _iLevel, _iScore, _hScore);
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
	if (_iAni == 1 || _Rac.state == 4){
		objectdc.SelectObject(&_Map._hMap);
		memdc.BitBlt(0, 0, rect.Width(), rect.Height(), &objectdc, 0, 0, SRCCOPY);
	}

	else {
		//너구리 주위  
		objectdc.SelectObject(&_Map._hMap);
		memdc.BitBlt(_Rac.x - 5, _Rac.y - 5, 60, 60, &objectdc, _Rac.x - 5, _Rac.y - 5, SRCCOPY);
		//적 주위 
		for (i = 0; i < Enemy::_EnemyCount; i++)
		{
			objectdc.SelectObject(&_Map._hMap);
			memdc.BitBlt(_Ene[i].x - 2, _Ene[i].y + 5, 54, 53, &objectdc, _Ene[i].x - 2, _Ene[i].y + 5, SRCCOPY);
		}
	}


	//// 점수 표시 (이전과 변화가 있을 때만 그린다.)
	static int Score;
	if (_iScore != Score || _iAni == 1 || _Rac.state == 4){
		objectdc.SelectObject(&_Map._hMap);
		memdc.BitBlt(20, 50, 86, 25, &objectdc, 20, 50, SRCCOPY);
		DrawDigit(memdc, 25, 50, _iScore, _hDigit, 7);
		Score = _iScore;
	}

	// 시간 바 표시 
	if (_iAni % 50 == 0 || _iAni == 1 || _Rac.state == 4) {
		objectdc.SelectObject(&_Map._hMap);
		memdc.BitBlt(600 - _iTime, 25, 50, 25, &objectdc, 200, 0, SRCCOPY);
		memdc.Rectangle(650 - _iTime, 25, 650, 50);
	}

	//먹은 과일 수 (이전과 변화가 있을 때만 그린다.)
	static char Eat;
	if (Item::_iEat != Eat || _Rac.state == 4) {
		for (i = 0; i < Item::_iEat; i++)
		{
			BITMAP info;
			_Item[0]._hFruit[_iLevel - 1].GetBitmap(&info);
			objectdc.SelectObject(&_Item[0]._hFruit[_iLevel - 1]);
			memdc.BitBlt(750, 490 - (i * 55), info.bmWidth, info.bmHeight, &objectdc, 0, 0, SRCCOPY);
		}
		Eat = Item::_iEat;
	}

	// 항아리 & 과일 표시 
	for (i = 0; i < 12; i++) {
		//항아리 
		if (_Item[i].ch == 'M' || _Item[i].ch == 'N' || _Item[i].ch == 'O')
		{
			objectdc.SelectObject(&_Item[0]._hPot);
			BITMAP info;
			_Item[0]._hPot.GetBitmap(&info);
			memdc.BitBlt(_Item[i].x, _Item[i].y, info.bmWidth, info.bmHeight, &objectdc, 0, 0, SRCCOPY);
		}

		//과일 
		else if (_Item[i].ch >= 'Q')
		{
			objectdc.SelectObject(&_Item[0]._hFruit[_iLevel - 1]);
			BITMAP info;
			_Item[0]._hFruit[_iLevel - 1].GetBitmap(&info);
			memdc.BitBlt(_Item[i].x, _Item[i].y, info.bmWidth, info.bmHeight, &objectdc, 0, 0, SRCCOPY);
		}

		//너구리가 먹은 것에 대한 점수 표시 
		//너구리가 먹으면 *로 대치하고 점수를 표시한다음에 .로 바꿈

		else if (_Item[i].ch == '*') {
			//과일 지우고 점수 표시 

			if (_ScoreShow == 0)
			{
				objectdc.SelectObject(&_Map._hMap);
				memdc.BitBlt(_Item[i].x, _Item[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY);
			}

			DrawDigit(memdc, _Item[i].x, _Item[i].y + 25, _iItemScoreRate, _hDigit_sm);

			//점수를 10프레임 동안 보여짐 			
			if (++_ScoreShow == 11) {
				objectdc.SelectObject(&_Map._hMap);
				memdc.BitBlt(_Item[i].x, _Item[i].y + 25, 40, 14, &objectdc, 200, 0, SRCCOPY);
				_Item[i].ch = '.';
				_ScoreShow = 0;
			}
		}
		else if (_Item[i].ch == '#') {
			objectdc.SelectObject(&_Map._hMap);
			memdc.BitBlt(_Item[i].x, _Item[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY);
			_Item[i].ch = '.';
		}
	}

	//적 표시 
	//뱀과 일반적인 적을 따로 그리는 이유는 투명 효과(Alpha) 때문에.	

	for (i = 0; i < Enemy::_EnemyCount; i++) {

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
					objectdc.SelectObject(&_Map._hMap);
					memdc.BitBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY); //검은색으로 기존의 것을 지우기 (200,0 ~ 250,50은 검정색)

					BLENDFUNCTION bf;
					bf.BlendOp = AC_SRC_OVER;
					bf.BlendFlags = 0;
					bf.SourceConstantAlpha = _Ene[i].alpha;
					bf.AlphaFormat = 0;

					objectdc.SelectObject(&_Ene[0]._hSnakeRight);

					BITMAP info;
					_Ene[0]._hSnakeRight.GetBitmap(&info);
					memdc.AlphaBlend(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, bf);
				}
				else
				{
					objectdc.SelectObject(&_Ene[0]._hSnakeRight);
					BITMAP info;
					_Ene[0]._hSnakeRight.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}
			else if (_Ene[i].alpha != 255) {
				_Ene[i].alpha += 5;	//선명하게  
				objectdc.SelectObject(&_Map._hMap);
				memdc.BitBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY); //검은색으로 기존의 것을 지우기 (200,0 ~ 250,50은 검정색)

				BLENDFUNCTION bf;
				bf.BlendOp = AC_SRC_OVER;
				bf.BlendFlags = 0;
				bf.SourceConstantAlpha = _Ene[i].alpha;
				bf.AlphaFormat = 0;

				objectdc.SelectObject(&_Ene[0]._hSnakeLeft);

				BITMAP info;
				_Ene[0]._hSnakeLeft.GetBitmap(&info);
				memdc.AlphaBlend(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, bf);
			}

			else // 방향(왼쪽을 보고 있을때)
			{
				objectdc.SelectObject(&_Ene[0]._hSnakeLeft);
				BITMAP info;
				_Ene[0]._hSnakeLeft.GetBitmap(&info);
				memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
			}
		}
	}



	//일반적인 적 
	for (i = 0; i < Enemy::_EnemyCount; i++) {

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
					objectdc.SelectObject(&_Ene[0]._hEnemyRightRed);
					BITMAP info;
					_Ene[0]._hEnemyRightRed.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}

				else
				{
					objectdc.SelectObject(&_Ene[0]._hEnemyLeftRed);
					BITMAP info;
					_Ene[0]._hEnemyLeftRed.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}
			}
			else {
				if (_Ene[i].state == FALSE) //방향
				{
					objectdc.SelectObject(&_Ene[0]._hEnemyRight);
					BITMAP info;
					_Ene[0]._hEnemyRight.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}
				else
				{
					objectdc.SelectObject(&_Ene[0]._hEnemyLeft);
					BITMAP info;
					_Ene[0]._hEnemyLeft.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}
			}
		}
	}

	////적 충돌 감지 
	_Rac.CheckCollision_Enemy(_Ene);

	////너구리 
	switch (_Rac.state) {
	case 1:
		objectdc.SelectObject(&_Rac._hStand);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));
		break;

	case 2:
		objectdc.SelectObject(&_Rac._hLeft);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, _Rac.step * 50, 0, 50, 50, RGB(0, 0, 0));
		break;

	case 3:
		objectdc.SelectObject(&_Rac._hRight);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, _Rac.step * 50, 0, 50, 50, RGB(0, 0, 0));
		break;

	case 4:
		objectdc.SelectObject(&_Rac._hUpDown);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, _Rac.step * 50, 0, 50, 50, RGB(0, 0, 0));
		break;

	case 5:
		// 점프 패턴을 읽어 와서 그림 
		_Rac.x += _Rac._StandJump[_Rac._JumpFrame].x;
		_Rac.y += _Rac._StandJump[_Rac._JumpFrame].y;

		objectdc.SelectObject(&_Rac._hStand);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_Rac._StandJump[_Rac._JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));

		_Rac._JumpFrame++;

		if (_Rac._JumpFrame == 10) {
			_Rac._JumpFrame = 0;	//초기화 
			_Rac.state = 1;	//착지 하면 다시 1상태로 
		}
		break;

	case 6:
		//화면 왼쪽 끝이므로 화면 밖으로 안나가게 
		if (_Rac.x >= 30)
			_Rac.x += _Rac._LeftShortJump[_Rac._JumpFrame].x;
		_Rac.y += _Rac._LeftShortJump[_Rac._JumpFrame].y;

		objectdc.SelectObject(&_Rac._hLeftJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_Rac._LeftShortJump[_Rac._JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));


		_Rac._JumpFrame++;

		if (_Rac._JumpFrame == 11) {
			_Rac._JumpFrame = 0;
			_Rac.state = 2;
			//충돌 검사 
			//이 프로그램은 화살표키로 움직일때 충동 검사를 (압정, 낭떠러지)한다.
			//문제는 너구리가 점프를 끝내고 바닥에 착지 하면 
			//방향키를 안눌렀기 때문에 충돌 검사가 안된다.
			//따라서 착지하면 충돌검사를 한다.
			_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate, _iScore);
		}

		break;

	case 7:
		//화면 왼쪽 끝이므로 화면 밖으로 안나가게 
		if (_Rac.x >= 30)
			_Rac.x += _Rac._LeftLongJump[_Rac._JumpFrame].x;
		_Rac.y += _Rac._LeftLongJump[_Rac._JumpFrame].y;

		objectdc.SelectObject(&_Rac._hLeftJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_Rac._LeftLongJump[_Rac._JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));


		_Rac._JumpFrame++;

		if (_Rac._JumpFrame == 17) {
			_Rac._JumpFrame = 0;
			_Rac.state = 2;
			//충돌 검사 
			//이 프로그램은 화살표키로 움직일때 충동 검사를 (압정, 낭떠러지)한다.
			//문제는 너구리가 점프를 끝내고 바닥에 착지 하면 
			//방향키를 안눌렀기 때문에 충돌 검사가 안된다.
			//따라서 착지하면 충돌검사를 한다.
			_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate, _iScore);
		}
		break;

	case 8:
		//오른쪽 경계면 
		//1층은 y좌표 775, 2층이상은 y좌표 670 
		if ((_Rac.x <= 670 && is_up == true) || (_Rac.x <= 775 && is_up == false))
			_Rac.x -= _Rac._LeftShortJump[_Rac._JumpFrame].x;
		_Rac.y += _Rac._LeftShortJump[_Rac._JumpFrame].y;

		objectdc.SelectObject(&_Rac._hRightJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_Rac._LeftShortJump[_Rac._JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));


		_Rac._JumpFrame++;

		if (_Rac._JumpFrame == 11) {
			_Rac._JumpFrame = 0;
			_Rac.state = 3;
			//충돌 검사 
			//이 프로그램은 화살표키로 움직일때 충동 검사를 (압정, 낭떠러지)한다.
			//문제는 너구리가 점프를 끝내고 바닥에 착지 하면 
			//방향키를 안눌렀기 때문에 충돌 검사가 안된다.
			//따라서 착지하면 충돌검사를 한다.
			_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate, _iScore);

		}

		break;

	case 9:
		//오른쪽 경계면 
		//1층은 y좌표 775, 2층이상은 y좌표 670 
		if ((_Rac.x <= 670 && is_up == true) || (_Rac.x <= 775 && is_up == false))
			_Rac.x -= _Rac._LeftLongJump[_Rac._JumpFrame].x;
		_Rac.y += _Rac._LeftLongJump[_Rac._JumpFrame].y;

		objectdc.SelectObject(&_Rac._hRightJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_Rac._LeftLongJump[_Rac._JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));

		_Rac._JumpFrame++;

		if (_Rac._JumpFrame == 17) {
			_Rac._JumpFrame = 0;
			_Rac.state = 3;
			//충돌 검사 
			//이 프로그램은 화살표키로 움직일때 충동 검사를 (압정, 낭떠러지)한다.
			//문제는 너구리가 점프를 끝내고 바닥에 착지 하면 
			//방향키를 안눌렀기 때문에 충돌 검사가 안된다.
			//따라서 착지하면 충돌검사를 한다.
			_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate, _iScore);
		}

		break;

	case 10: //떨어지는 너구리  
		if (_bIsDrop_Sound == FALSE) {
			PlaySound(NULL, AfxGetInstanceHandle(), 0);
			PlaySound(MAKEINTRESOURCE(IDR_RAC_DROP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
			_bIsDrop_Sound = TRUE;
		}

		if (_Rac.y >= 578) {
			_Rac.y = 578;
			//다 떨어진 상태

			objectdc.SelectObject(&_Rac._hDie);
			memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));

			_Rac.state = 11;
		}
		else {
			_Rac.y += 5;
			//덜 떨어진 상태 

			objectdc.SelectObject(&_Rac._hDrop);
			memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_iAni / 2 % 6) * 50, 0, 50, 50, RGB(0, 0, 0));
		}
		break;

	case 11: //너구리 떨어진 상태 				
		break;

	}


	pView->Invalidate(FALSE);
}

void CGame::GameCycle()
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

void CGame::GameClear()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView* pView = (CChildView*)pFrame->GetChildView();

	CClientDC dc(pView);
	pView->GetClientRect(&rect);
	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	CBitmap* OldBit;
	CBrush BackBrush, *OldBrush;

	static int bonus;

	if (_cBit.m_hObject == NULL)
		_cBit.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());

	OldBit = memdc.SelectObject(&_cBit);

	BackBrush.CreateSolidBrush(RGB(0, 0, 0));
	OldBrush = memdc.SelectObject(&BackBrush);

	// 화면 지우기
	_iAni++;

	if (_iAni == 1)
		memdc.FillRect(&rect, &BackBrush);


	// 마지막 레벨 성공여부	
	if (_iLevel != LAST_LEVEL) {

		if (_iAni == 130) {
			_iScore += bonus;
			_iLevel++;
			Init();
			_Map.LoadMap(rect, _Ene, _Item, _Rac, _iLevel, _iScore, _hScore);
			_GameState = 1;
		}

		//남은 시간에 따른 보너스 점수 
		if (_iTime > 200)
			bonus = 5000;
		else
			bonus = 2000;

		// bonus 점수표시
		DrawDigit(memdc, 450, 255, bonus, _hDigit, 7);

		//'BONUS'
		objectdc.SelectObject(&_hBonus);
		memdc.TransparentBlt(340, 255, 87, 22, &objectdc, 0, 0, 87, 22, RGB(0, 0, 0));

		//'Next'
		objectdc.SelectObject(&_hNext);
		memdc.TransparentBlt(765, 622, 51, 22, &objectdc, 0, 0, 51, 22, RGB(0, 0, 0));

		//과일
		BITMAP info;
		_Item[0]._hFruit[_iLevel].GetBitmap(&info);
		objectdc.SelectObject(&_Item[0]._hFruit[_iLevel]);
		memdc.TransparentBlt(830, 600, info.bmWidth, info.bmHeight, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));

		if (_iAni == 1)
			PlaySound(MAKEINTRESOURCE(IDR_CLEAR), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	}
	else {
		//마지막 레벨 성공 	
		if (_iAni == 400) {
			Init();
			_GameState = 0;
		}
		// ending 메세지
		objectdc.SelectObject(&_hEnding);
		memdc.TransparentBlt(100, 150, 700, 197, &objectdc, 0, 0, 700, 197, RGB(0, 0, 0));
		// 아기
		objectdc.SelectObject(&_hBaby);
		memdc.BitBlt(750, 420, 42, 43, &objectdc, (_iAni / 4 % 2) * 42, 0, SRCCOPY);
	}

	// 'SCORE' 표시
	objectdc.SelectObject(&_hScore);
	memdc.TransparentBlt(25, 25, 75, 23, &objectdc, 0, 0, 75, 23, RGB(0, 0, 0));

	// 점수 표시 
	DrawDigit(memdc, 25, 50, _iScore, _hDigit, 7);

	pView->Invalidate(false);
}

void CGame::GameOver()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView* pView = (CChildView*)pFrame->GetChildView();

	CClientDC dc(pView);

	pView->GetClientRect(&rect);

	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	CBitmap* OldBit;

	if (_cBit.m_hObject == NULL)
		_cBit.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	OldBit = memdc.SelectObject(&_cBit);

	//인트로
	CBrush backBrush;
	backBrush.CreateSolidBrush(RGB(0, 0, 0));

	memdc.FillRect(&rect, &backBrush);

	CDC game_overdc;
	game_overdc.CreateCompatibleDC(&memdc);

	CDC scoredc;
	scoredc.CreateCompatibleDC(&memdc);

	CDC drop_racoondc;
	drop_racoondc.CreateCompatibleDC(&memdc);

	game_overdc.SelectObject(&_hGameOver);
	drop_racoondc.SelectObject(&_Rac._hDrop);
	scoredc.SelectObject(&_hScore);


	if (_iAni != 350)
		_iAni++;
	else {
		Init();
		_GameState = 0;
	}
	// 'SCORE' 표시
	memdc.BitBlt(25, 25, 75, 23, &scoredc, 0, 0, SRCCOPY);

	// 점수 표시 
	static int Score;
	if (_iScore != Score || _iAni == 1){
		memdc.BitBlt(200, 50, 100, 25, &objectdc, 200, 50, SRCCOPY);
		DrawDigit(memdc, 25, 50, _iScore, _hDigit, 7);
		Score = _iScore;
	}



	//바닥 그리기 
	CBrush brush;
	brush.CreateSolidBrush(RGB(165, 113, 66));
	memdc.Rectangle(0, 585, 900, 670);

	static int i, j;
	j = 0;
	for (i = 585; i < 670; i += j) {
		j++;
		memdc.MoveTo(0, i);
		memdc.LineTo(900, i);
	}
	j = 0;

	//'GAME OVER'
	if (_iAni < 50) {
		memdc.BitBlt(-340 + _iAni * 10, 200, 280, 72, &game_overdc, 0, 0, SRCCOPY);
		memdc.BitBlt(940 - _iAni * 10, 200, 280, 72, &game_overdc, 280, 0, SRCCOPY);
	}
	else
		memdc.BitBlt(160, 200, 560, 72, &game_overdc, 0, 0, SRCCOPY);

	//떨어져라 너구리야
	if (_iAni > 50 && _iAni < 110)
		memdc.BitBlt(430, (_iAni - 55) * 10, 50, 50, &drop_racoondc, (_iAni / 2 % 6) * 50, 0, SRCCOPY);

	else if (_iAni >= 110){
		drop_racoondc.SelectObject(&_Rac._hDie);
		memdc.TransparentBlt(430, 540, 50, 50, &drop_racoondc, 0, 0, 50, 50, RGB(0, 0, 0));
	}


	//사운드 출력파트
	if (_iAni == 1)
		PlaySound(MAKEINTRESOURCE(IDR_GAMEOVER), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

	if (_iAni == 110)
		PlaySound(MAKEINTRESOURCE(IDR_RAC_DIE), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

	pView->Invalidate(false);
}

void CGame::Init()
{
	//초기화
	_Rac.state = 1;			//너구리는 정면을 보고 있다 
	_Rac.x = 775;			//너구리의 시작 위치 
	_Rac.y = 578;			//너구리의 시작 위치 
	_Rac.speedx = 5;		//너구리 이동 속도 
	_Rac.speedy = 5;		//너구리 이동 속도 
	_iTime = 500;			//게임 제한 시간 
	_iItemScoreRate = 5;	//아이템 점수, 2배씩 곱해지면서 증가 
	Item::_iEat = 0;		//먹은 과일수 
	_iAni = 0;				//애니메이션 효과를 위해 
	_bIsDrop_Sound = FALSE;	//너구리가 떨어질때 나는 소리 상태 

	Enemy::_EnemyCount = 0;	//적의 숫자 

	_ScoreShow = 0;			//먹은 과일 점수 표시 시간 
	_Rac._JumpFrame = 0;			//점프를 보여 줄때 필요 (카운터)

	is_up = false;
}

void CGame::DrawDigit(CDC& cDC, int x, int y, int score, CBitmap& cBit, int cipher, COLORREF crTransColor)
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

void CGame::HandleKeys()
{


	switch (_GameState) {

		//인트로 화면 
	case 0:
		if (GetAsyncKeyState(JUMP) < 0) {
			//인트로 음악 종료 
			PlaySound(NULL, AfxGetInstanceHandle(), 0);
			// 초기화 
			_iLevel = 1;
			Raccoon::_iLive = LIVE;
			_iScore = 0;
			Init();
			_Map.LoadMap(rect, _Ene, _Item, _Rac, _iLevel, _iScore, _hScore);
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
				if (_Map._cMap[(_Rac.y) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			/*else if (GetAsyncKeyState(DOWN) < 0) {
				if (_Map._cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}*/
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
					_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate, _iScore);
				} //키 버퍼 
				if (GetAsyncKeyState(JUMP) < 0) {
					PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					_Rac.state = 7;
				}
			}
			else if (GetAsyncKeyState(RIGHT) < 0)
				_Rac.state = 3;

			else if (GetAsyncKeyState(UP) < 0) {
				if (_Map._cMap[(_Rac.y - 25) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			/*else if (GetAsyncKeyState(DOWN) < 0) {
				if (_Map._cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}*/
			else if (GetAsyncKeyState(JUMP) < 0) {
				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				_Rac.state = 6;
			}

			break;

		case 3:
			if (GetAsyncKeyState(LEFT) < 0)
				_Rac.state = 2;

			else if (GetAsyncKeyState(RIGHT) < 0) {
				if ((_Rac.x <= 670 && is_up == true) || (_Rac.x <= 775 && is_up == false)) {
					_Rac.x += _Rac.speedx;
					_Rac.step = !_Rac.step;
					if (_Rac.x % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
					_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate, _iScore);
				} // 키 버퍼 
				if (GetAsyncKeyState(JUMP) < 0)  {
					PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					_Rac.state = 9;
				}
			}
			else if (GetAsyncKeyState(UP) < 0) {
				if (_Map._cMap[(_Rac.y - 25) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			/*else if (GetAsyncKeyState(DOWN) < 0) {
				if (_Map._cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}*/
			else if (GetAsyncKeyState(JUMP) < 0) {
				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				_Rac.state = 8;
			}

			break;

		case 4:
			if (GetAsyncKeyState(UP) < 0)
				if (_Map._cMap[(_Rac.y + 20) / 25][(_Rac.x + 20) / 25] == 'F') {
					//_Rac.y -= _Rac.speedy;
					
					_Map.MoveMap(_Ene);
					is_up = true;
					
					for (int i = 0; i < 12; i++){
						_Item[i].y += 5*_Rac.speedy;
					}
						_Ene[i].y += 5*_Rac.speedy;
					}

					_Rac.step = !_Rac.step;
					if ((_Rac.y - 3) % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
				}
				else
					_Rac.state = 1;	
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
