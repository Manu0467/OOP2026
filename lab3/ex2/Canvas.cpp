#include "Canvas.h"
#include <stdio.h>

Canvas::Canvas(int w, int h) {

	width = w;
	height = h;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++) {
			canvas[i][j] = 32;
		}
	}
}

void Canvas::DrawCircle(int x0, int y0, int ray, char ch)
{
	int y = -ray;
	int x = 0;
	int d=-ray;

	while (x < -y) {

		if (d > 0)
		{
			y++;
			d += 2 * (x + y) + 1;
		}
		else {
			d += 2 * x + 1;
		}

		canvas[x0 + x][y0 + y] = ch;
		canvas[x0 + x][y0 - y] = ch;
		canvas[x0 - x][y0 + y] = ch;
		canvas[x0 - x][y0 - y] = ch;
		canvas[y0 + y][x0 + x] = ch;
		canvas[y0 - y][x0 + x] = ch;
		canvas[y0 + y][x0 - x] = ch;
		canvas[y0 - y][x0 - x] = ch;

		x++;
	}
}

void Canvas::FillCircle(int x0, int y0, int ray, char ch)
{

	for (int x = y0-ray; x <= y0+ray; x++)
	{
		for (int y = x0 - ray; y <= x0 + ray; y++) {
			if ((x-x0)* (x - x0) + (y-y0)* (y - y0) < ray*ray)
			{
					canvas[y][x] = ch; 	
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (left < right)
	{
		for (int i = left; i <= right; i++) {
			canvas[top][i] = ch;
			canvas[bottom][i] = ch;
		}
		if (top < bottom)
		{
			for (int i = top; i <= bottom; i++) {
				canvas[i][left] = ch;
				canvas[i][right] = ch;
			}
		}
		else
		{
			for (int i = top; i >= bottom; i--) {
				canvas[i][left] = ch;
				canvas[i][right] = ch;
			}
		}

	}
	else
	{
		for (int i = left; i >= right; i--) {
			canvas[top][i] = ch;
			canvas[bottom][i] = ch;
		}
		if (top < bottom)
		{
			for (int i = top; i <= bottom; i++) {
				canvas[i][left] = ch;
				canvas[i][right] = ch;
			}
		}
		else
		{
			for (int i = top; i >= bottom; i--) {
				canvas[i][left] = ch;
				canvas[i][right] = ch;
			}
		}
	}

	//  0  1  2  3  4  5  6  7  8  9
	//0 *  *  *  *  *  *  *  *  *  * 
	//1 *  *  *  *  *  *  *  *  *  * 
	//2 *  *  *  *  *  *  *  *  *  * 
	//3 *  *  *  *  *  *  *  *  *  * 
	//4 *  *  *  *  *  *  *  *  *  * 
	//5 *  *  *  *  *  *  *  *  *  * 
	//6 *  *  *  *  *  *  *  *  *  * 
	//7 *  *  *  *  *  *  *  *  *  * 
	//8 *  *  *  *  *  *  *  *  *  * 
	//9 *  *  *  *  *  *  *  *  *  * 
 


}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{


	if (left < right)
	{
		if (top < bottom)
		{
			for (int i = top + 1; i < bottom; i++) {
				for (int j = left + 1; j < right; j++)
				{
					canvas[i][j] = ch;
				}
			}
		}
		else
		{
			for (int i = top - 1; i > bottom; i--) {
				for (int j = left + 1; j < right; j++)
				{
					canvas[i][j] = ch;
				}
			}
		}

	}
	else
	{
		if (top < bottom)
		{
			for (int i = top + 1; i < bottom; i++) {
				for (int j = left - 1; j > right; j++)
				{
					canvas[i][j] = ch;
				}
			}
		}
		else
		{
			for (int i = top - 1; i > bottom; i--) {
				for (int j = left - 1; j > right; j++)
				{
					canvas[i][j] = ch;
				}
			}
		}
	}


}

void Canvas::SetPoint(int x, int y, char ch)
{
	canvas[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int w = x2 - x1;
	int h = y2 - y1;
	int D = 2 * h - w;
	int y = y1;
	for (int x = x1; x <= x2; x++)
	{
		canvas[y][x] = ch; //din moment ce folosim coordonatele matematice ca parametri aici acestea trebuie inversate pentru a avea un output corect
		if (D > 0)
		{
			y++;
			D += 2 *(h-w);
		}
		else
		{
			D += 2 * h;
		}
		
	}
}

void Canvas::Print()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++) {
			printf("%2c", canvas[i][j]);
		}
		printf("\n");
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++) {
			canvas[i][j] = 32;
		}
	}
}
