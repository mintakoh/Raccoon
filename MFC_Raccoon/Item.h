#pragma once

//����, �׾Ƹ� 
class Item
{
public:
	Item();
	~Item();

	int x;
	int y;
	char ch;

	// ������ �� ����
	static int _ItemCount;

	//���� ���� ��
	static char		_iEat;

	// �׾Ƹ�
	CBitmap		_hPot;

	//����
	CBitmap		_hFruit[4];
};

