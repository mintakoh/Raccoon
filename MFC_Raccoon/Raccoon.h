#pragma once

class Raccoon
{
public:
	Raccoon();
	~Raccoon();

	int x;				// x��ǥ
	int y;				// y��ǥ 
	char state;			// �ʱ��� ���� (���� , ������ , ���� ......) [�ʱ����������̵� ����]
	BOOL step;			// �����϶� ���ϸ��̼��� ���� 
	char speedx;		// �ӵ� 
	char speedy;		// �ӵ� 
};

