#include "Body.h"
#include "ConsoleEngineCore.h"
#include "ConsoleScreen.h"

// �ʱ� ���� ����
Body::Body() 
{
	SetChar('B');

	// Head�� Body�� ��ġ���� ���� ���� ���� ����
	// ��ũ���� ũ�� ��� -> ���� �ִ� ���� ����

	srand(time(0));
	//int a = rand() % 10; // 0~9
	//int b = rand() % 5; // 0~4
	
	// LHE: 0, 0 �ȵǵ��� ���� �߰� �ʿ�
	int a = 0;
	int b = 0;
	while (a == 0 && b == 0)
	{
		a = rand() % 10;
		b = rand() % 5;
	}

	SetPos({ a,b });
}




Body::~Body() 
{
}

void Body::FollowHead()
{

}

