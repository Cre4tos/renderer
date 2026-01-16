#include "console.h"
#include <windows.h>

void set_cursor_pos(int x, int y)
{
    COORD pos;
    pos.X = static_cast<SHORT>(x);
    pos.Y = static_cast<SHORT>(y);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}