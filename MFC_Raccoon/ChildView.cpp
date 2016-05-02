
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
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
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

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	//시간
	if (_iAni == 1000)
		_iAni = 0;
	else
		_iAni++;

	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	CRect rect;
	GetClientRect(&rect);

	CBitmap screen;
	screen.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());

	memdc.SelectObject(&screen);

	CBitmap _hLeft;
	_hLeft.LoadBitmapW(IDB_LEFT);
	CBitmap _hStand;
	_hStand.LoadBitmapW(IDB_STAND);
	CBitmap _hRight;
	_hRight.LoadBitmapW(IDB_RIGHT);
	CBitmap _hSurprise;
	_hSurprise.LoadBitmapW(IDB_SURPRISE);
	CBitmap _hLets;
	_hLets.LoadBitmapW(IDB_LETS);


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
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));
		else
			memdc.TransparentBlt(720, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));

		if (_iAni >= 50 && _iAni <= 70) 
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));
		else if (_iAni >= 70) 
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));

		if (_iAni >= 70 && _iAni <= 90) 
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));
		else if (_iAni >= 90) 
			memdc.TransparentBlt(520, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));
		
		if (_iAni >= 90 && _iAni <= 110)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));
		else if (_iAni >= 110)
			memdc.TransparentBlt(420, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));

		if (_iAni >= 110 && _iAni <= 130)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));
		else if (_iAni >= 130)
			memdc.TransparentBlt(320, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));

		if (_iAni >= 130 && _iAni <= 150)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));
		else if (_iAni >= 150)
			memdc.TransparentBlt(220, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));

		if (_iAni >= 150 && _iAni <= 170)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));
		else if (_iAni >= 170)
			memdc.TransparentBlt(120, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0,0,0));

		//너구리 몸 흔들기 -> Dance ㅡㅡ;;
	}
	else if (_iAni < 437) {
		objectdc.SelectObject(&_hStand);
		for (int i = 120; i <= 520; i += 100)
			memdc.TransparentBlt(i, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0,0,0));
		
		if (_iAni < 250)
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, (1 - _iAni / 19 % 2) * 50, 0, 50, 50, RGB(0,0,0));
		else
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0,0,0));

		if (_iAni > 220 && _iAni < 255) {
			objectdc.SelectObject(_hSurprise);
			memdc.TransparentBlt(640, 435, 29, 21, &objectdc, 0, 0, 29, 21, RGB(0,0,0));
		}

		objectdc.SelectObject(_hStand);
		memdc.TransparentBlt(720, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0,0,0));
	}
	else {
		objectdc.SelectObject(_hRight);
		for (int i = 120; i <= 520; i += 100)
			memdc.TransparentBlt(i, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0,0,0));

		objectdc.SelectObject(_hStand);
		memdc.TransparentBlt(620, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0,0,0));

		objectdc.SelectObject(_hSurprise);
		memdc.TransparentBlt(640, 435, 29, 21, &objectdc, 0, 0, 29, 21, RGB(0,0,0));

		objectdc.SelectObject(_hLeft);
		memdc.TransparentBlt(720, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0,0,0));
	}

	if (_iAni >= 171) {
		objectdc.SelectObject(_hLets);
		memdc.BitBlt(220, 120, 455, 218, &objectdc, 0, 0, SRCCOPY);
	}

	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memdc, 0, 0, SRCCOPY);
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

void CChildView::GameCycle()
{
	switch (_GameState) {
	case 0:
		_bIsDrawAll = FALSE;
		Invalidate(false);
		//GameIntro();
		break;

	case 1:
		_bIsDrawAll = FALSE;
		//GamePlay();
		break;

	case 2:
		_bIsDrawAll = FALSE;
		//GameClear();
		break;

	case 3:
		_bIsDrawAll = FALSE;
		//GameOver();
		break;
	}
}
