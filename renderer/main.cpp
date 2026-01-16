#pragma once
#define NOMINMAX
#include <windows.h>
#include <thread>
#include "buffer.h"
#include "buffer_formatter.h"
#include "draw.h"
int main()
{
	const int target_frames = 60;
	const int target_ms = 1000 / target_frames;
	int rows = 30,
		cols = 120;
	buffer a{ rows, cols, ' ' };
	buffer b{ rows, cols, ' ' };

	buffer* front = &a;
	buffer* back  = &b;

	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);

	while (true) {
		//time querrying
		LARGE_INTEGER time_start;
		QueryPerformanceCounter(&time_start);

		//clearing
		back->clear();

		//drawing
		draw_line(back, 'c', - 2, -2, 5, 5);
		draw_o(back);

		//displaying
		back->display();

		//buffer swap
		std::swap(front, back);


		//time querrying
		LARGE_INTEGER time_end;
		QueryPerformanceCounter(&time_end);

		//time calculting
		long long delta_time = 
			time_end.QuadPart - time_start.QuadPart;
		long long ms = (1000 * delta_time) / freq.QuadPart;

		//sleeping
		if(ms<target_ms)
		 std::this_thread::sleep_for(
			 std::chrono::milliseconds(target_ms - ms));
	}
}
