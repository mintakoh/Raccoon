
// MainFrm.h : CMainFrame Ŭ������ �������̽�
//

#pragma once
#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:
	CChildView* GetChildView();

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// �����Դϴ�.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ��Ʈ�� ������ ���Ե� ����Դϴ�.
	//���� ����
	//CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CChildView    m_wndView;

// ������ �޽��� �� �Լ�
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	void GameActivate()
	{
		// ȭ���� ���� �ٽ� �׸��� ���� 
		GetChildView()->_bIsDrawAll = TRUE;
		m_bSleep = false;
	}

	void GameDeactivate()
	{
		// ȭ���� ���� �ٽ� �׸��� ���� 
		GetChildView()->_bIsDrawAll = TRUE;
		m_bSleep = true;
	}
	bool m_bSleep;
};


