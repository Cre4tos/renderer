#include "buffer.h"
#include <print>
#include <windows.h>

// Constructor
buffer::buffer(int rows, int cols, char fill)
{
    height = rows;
    width = cols;
    data.resize(height * width, fill);
}

// Clear the buffer
void buffer::clear()
{
    for (int i = 0; i < static_cast<int>(data.size()); i++) {
        data[i] = '.';
    }
}

// Put a character at logical coordinates
void buffer::put(int x, int y, char c)
{
    int row = -y + height / 2;
    int col =  x + width  / 2;
    if (row < 0 || row >= height
        || col < 0 || col >= width) return;
    int index = row * width + col;
    data[index] = c;
}

void buffer::display()
{
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
    std::print("{}", *this);
}