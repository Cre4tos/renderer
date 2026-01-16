#pragma once
#include <vector>
#include <format>

// Simple text buffer, coordinates centered
class buffer {
private:
    std::vector<char> data;
    int width, height;
public:
    buffer(int rows, int cols, char fill = ' ');
    void clear();
    void put(int x, int y, char c);
    void display();

    friend struct std::formatter<buffer, char>;
};