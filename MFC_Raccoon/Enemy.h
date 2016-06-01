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
	char type;		//�Ϲ����� �� 0, �� 1, ���� 2

	char speed_y;	// y �ӵ� (����)
	bool state_y;	// y ���� (����)

	// ��
	CBitmap		_hEnemyRight;
	CBitmap		_hEnemyLeft;
	CBitmap		_hEnemyRightRed;
	CBitmap		_hEnemyLeftRed;

	//��
	CBitmap		_hSnakeLeft;
	CBitmap		_hSnakeRight;

	//����
	CBitmap		_hGhostRight;
	CBitmap		_hGhostLeft;

	static int _EnemyCount;

};

