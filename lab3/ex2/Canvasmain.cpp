#include<stdio.h>
#include"Canvas.h"
#include<Windows.h>

int main() {

	Canvas c(40, 40);
	c.DrawRect(6, 2, 23, 9, '*');
	c.FillRect(6, 2, 23, 9, '$');
	c.Print();
	c.Clear();
	c.DrawLine(1, 3, 29, 9, '*');
	c.Print();
	c.Clear();
	c.DrawCircle(10, 10, 5, '*');
	c.Print();
	c.FillCircle(10, 10, 5, '^');
	c.Print();

}