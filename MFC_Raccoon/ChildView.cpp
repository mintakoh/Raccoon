
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
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	memdc.SelectObject(&game._cBit);

	CRect rect;
	GetClientRect(&rect);

	switch (game._GameState) {
	case 0:
		// 171은 너구리가 자리를 다 잡고 춤추기 시작하는 시점 
		if (game._bIsDrawAll == TRUE || game._iAni == 1 || game._iAni == 171)
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
		if (game._bIsDrawAll == TRUE || game._iAni == 1)
			dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memdc, 0, 0, SRCCOPY);
		else {

			//점수
			dc.BitBlt(25, 50, 100, 25, &memdc, 25, 50, SRCCOPY);

			//시간 
			dc.BitBlt(150, 25, 500, 25, &memdc, 150, 25, SRCCOPY);

			//먹은과일 
			dc.BitBlt(750, 110, 50, 440, &memdc, 750, 110, SRCCOPY);

			//너구리 주위 
			dc.BitBlt(game._Rac.x - 10, game._Rac.y - 10, 70, 70, &memdc, game._Rac.x - 10, game._Rac.y - 10, SRCCOPY);

			//적 주위 
			for (int i = 0; i < game._EnemyCount; i++)
				dc.BitBlt(game._Ene[i].x - 2, game._Ene[i].y + 5, 60, 50, &memdc, game._Ene[i].x - 2, game._Ene[i].y + 5, SRCCOPY);

			//아이템 주위 
			for (int i = 0; i < 12; i++)
				dc.BitBlt(game._Item[i].x, game._Item[i].y, 50, 50, &memdc, game._Item[i].x, game._Item[i].y, SRCCOPY);
		}
		break;

	case 2:
		if (game._bIsDrawAll == TRUE || game._iAni == 1)
			dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memdc, 0, 0, SRCCOPY);
		else
			dc.BitBlt(500, 400, 550, 450, &memdc, 500, 400, SRCCOPY);
		break;

	case 3:
		if (game._bIsDrawAll == TRUE || game._iAni == 1)
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
