
// MFC_Raccoon.h : MFC_Raccoon ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFC_RaccoonApp:
// �� Ŭ������ ������ ���ؼ��� MFC_Raccoon.cpp�� �����Ͻʽÿ�.
//

class CMFC_RaccoonApp : public CWinApp
{
public:
	CMFC_RaccoonApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnIdle(LONG lCount);
};

extern CMFC_RaccoonApp theApp;
