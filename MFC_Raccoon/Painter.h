#pragma once
class CPainter
{
public:
	CPainter();
	CPainter(CWnd* parent);
	~CPainter();
	void onPaint(CDC* pDC);
	CWnd* m_parent;
};

