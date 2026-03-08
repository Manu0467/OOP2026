#include "Canvas.h"
#include <stdio.h>
#include <cstdarg>

Canvas::Canvas(int lines, int columns) {

	l = lines;
	c = columns;
	clear();
}

void Canvas::set_pixel(int x, int y, char ch) {

	canvas[x][y] = ch;
}
void Canvas::set_pixels(int count, ...) {
	
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++)
	{
		int x = va_arg(args, int);
		int y = va_arg(args, int);
		char ch = va_arg(args, char);
		set_pixel(x, y, ch);
	}

	va_end(args);

}
void Canvas::print() const {

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < c; j++) {

			printf("%c", canvas[i][j]);
		}
		printf("\n");
	}
}

void Canvas::clear() {

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < c; j++) {
			canvas[i][j] = 32;
		}
	}
}