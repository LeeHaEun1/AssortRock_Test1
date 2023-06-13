#include "Head.h"
#include <conio.h>
#include "ConsoleEngineCore.h"

Head::Head() 
{
    SetChar('H');
    SetPos({ 0,0 });
}

Head::~Head() 
{
    // Memory Leak
}

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

    // ����� �ݴ� �������� �̵� �Ұ�
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

    // �������� �Է��� Ű ����
    lastSelect = Select;
}