#pragma once
#include "buffer.h"

// API exported from renderer\\buffer.cpp
void draw_o(buffer* b);
void draw_line(buffer* b, char c, int x1, int y1, int x2, int y2);