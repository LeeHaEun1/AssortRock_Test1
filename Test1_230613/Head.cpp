#include "Head.h"
#include <conio.h>
#include "ConsoleEngineCore.h"
#include "Body.h"


Head::Head() 
{
    SetChar('H');
    SetPos({ 0,0 });
}

Head::~Head() 
{
    // Memory Leak
}

void Head::EatBodyCheck(Body& _Body, int4 _Pos)
{
    if (_Body.GetPos() == _Pos)
    {
        isBody = true;
        _Body.SetChar('B');
        _Body.SetPos(_Pos + int4::Left);
    }
    else
    {
        isBody = false;
    }
}

//void Head::AddBody(Body* _Body)
//{
//    if (isBody == true)
//    {
//        
//    }
//}

void Head::Tick(float _Time)
{
    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
    case 'a':
        MovePos = int4::Left;
        break;
    case 'd':
        MovePos = int4::Right;
        break;
    case 'w':
        MovePos = int4::Up;
        break;
    case 's':
        MovePos = int4::Down;
        break;
    case 'q':
        ConsoleEngineCore::EngineOff();
        break;
    default:
        break;
    }

    // 운동방향 반대 방향으로 이동 불가
    if (lastSelect == 'a' && Select == 'd')
    {
        return;
    }
    if (lastSelect == 'd' && Select == 'a')
    {
        return;
    }
    if (lastSelect == 'w' && Select == 's')
    {
        return;
    }
    if (lastSelect == 's' && Select == 'w')
    {
        return;
    }

    AddPos(MovePos);

    // 마지막에 입력한 키 저장
    lastSelect = Select;
}