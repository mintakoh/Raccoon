#pragma once


//�� (���� ���� ���� ó��, ���̴� ���� ���İ��� ������� �ʴ´�, �츸 ���)
class Enemy
{
public:
	Enemy();
	~Enemy();

	int x;			//x��ǥ
	int y;			//y��ǥ
	int alpha;		//�� ����ϴ� �����ϰ�
	char speed;		//�ӵ�
	bool state;		//����(�¿�)
	bool type;		//�Ϲ����� ��, ��
};

