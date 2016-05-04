
// ChildView.cpp : CChildView Ŭ������ ����
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


// CChildView �޽��� ó����

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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	memdc.SelectObject(&game._cBit);

	CRect rect;
	GetClientRect(&rect);

	switch (game._GameState) {
	case 0:
		// 171�� �ʱ����� �ڸ��� �� ��� ���߱� �����ϴ� ���� 
		if (game._bIsDrawAll == TRUE || game._iAni == 1 || game._iAni == 171)
			dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memdc, 0, 0, SRCCOPY);
		else
			dc.BitBlt(120, 430, 780, 70, &memdc, 120, 430, SRCCOPY);
		break;

	case 1:
		// ó������ ���� �� �׸��� �� ���Ĵ� ������ ���ؼ� ��ȭ�� �κи� �ٽ� �׸���.
		// �ӵ� ����� ���� �Ź� ���� �ٽ� �׸��� ���� 
		// ó���� �Ź� ȭ�� ��ü�� �ٽ� �׸��� ������µ�(���� �ϱ� ����)
		// ��Ƽ��200���� �׽�Ʈ ��� �ӵ��� ��û���� ���� 
		// �׷��� ���ϴ� �κи� �ٽ� �׸��� ���� ���� 
		// �׷��� ���ӿ��� ȭ���� �׸��� �κ��� ���� �������� 
		if (game._bIsDrawAll == TRUE || game._iAni == 1)
			dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memdc, 0, 0, SRCCOPY);
		else {

			//����
			dc.BitBlt(25, 50, 100, 25, &memdc, 25, 50, SRCCOPY);

			//�ð� 
			dc.BitBlt(150, 25, 500, 25, &memdc, 150, 25, SRCCOPY);

			//�������� 
			dc.BitBlt(750, 110, 50, 440, &memdc, 750, 110, SRCCOPY);

			//�ʱ��� ���� 
			dc.BitBlt(game._Rac.x - 10, game._Rac.y - 10, 70, 70, &memdc, game._Rac.x - 10, game._Rac.y - 10, SRCCOPY);

			//�� ���� 
			for (int i = 0; i < game._EnemyCount; i++)
				dc.BitBlt(game._Ene[i].x - 2, game._Ene[i].y + 5, 60, 50, &memdc, game._Ene[i].x - 2, game._Ene[i].y + 5, SRCCOPY);

			//������ ���� 
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

			//�������� �ʱ��� 
			dc.BitBlt(430, 0, 50, 590, &memdc, 430, 0, SRCCOPY);
		}
		break;
	}

	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}
