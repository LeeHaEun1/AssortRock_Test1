#include "Body.h"
#include "ConsoleEngineCore.h"
#include "ConsoleScreen.h"

// 초기 랜덤 생성
Body::Body() 
{
	SetChar('B');

	// Head나 Body가 위치하지 않은 곳에 랜덤 생성
	// 스크린의 크기 고려 -> 범위 있는 난수 생성

	srand(time(0));
	//int a = rand() % 10; // 0~9
	//int b = rand() % 5; // 0~4
	
	// LHE: 0, 0 안되도록 제한 추가 필요
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

