#include "draw.h"
#include <cmath>
#include <algorithm>

void draw_o(buffer* b)
{
	b->put(1, 1, 'o');
}

void draw_line(buffer* b, char c, int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps = std::max(std::abs(dx), std::abs(dy));
	if (steps == 0) { b->put(x1, y1, c); return; }
	double x_inc = static_cast<double>(dx) / steps;
	double y_inc = static_cast<double>(dy) / steps;
	double x = x1;
	double y = y1;
	for (int _ = 0; _ < steps + 1; _++) {
		b->put(static_cast<int>(std::round(x)), static_cast<int>(std::round(y)), c);
		x += x_inc;
		y += y_inc;
	}
}