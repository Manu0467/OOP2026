#include<stdio.h>
#include "Math.h"

int main() {

	Math c;

	printf("%d\n", c.Add(12, 24));
	printf("%d\n", c.Add(23, 3, 7));
	printf("%d\n", c.Add(12.4, 34.2));
	printf("%d\n", c.Add(12.7, 22.6, 23.4));
	printf("%d\n", c.Add(5, 2, 6, 7, 9, 123));
	printf("%d\n", c.Mul(12, 24));
	printf("%d\n", c.Mul(23, 3, 7));
	printf("%d\n", c.Mul(12.4, 34.2));
	printf("%d\n", c.Mul(12.7, 22.6, 23.4));
	printf("%s	\n", c.Add("12", "24"));
}