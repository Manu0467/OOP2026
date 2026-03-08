#pragma once
#include "Math.h"
#include <cstdarg>
#include<cstring>
#include <cstdlib>

int Math::Add(int a, int b) {

	return a + b;
}

int Math::Add(int a, int b, int c) {
	
	return a + b + c;
}

int Math::Add(double a, double b) {

	return a + b;
}

int Math::Add(double a, double b, double c) {

	return a + b + c;
}

int Math::Add(int count, ...) {

	int sum = 0;

	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++)
	{
		sum+=va_arg(args, int);
	}

	va_end(args);

	return sum;

}

int Math::Mul(int a, int b) {

	return a * b;
}

int Math::Mul(int a, int b, int c) {

	return a * b * c;
}

int Math::Mul(double a, double b) {

	return a * b;
}

int Math::Mul(double a, double b, double c) {

	return a * b * c;
}

char* Math::Add(const char* s1, const char* s2) {

	if (s1==nullptr || s2==nullptr)
	{
		return nullptr;
	}
	char* s = (char*)malloc(strlen(s1) + strlen(s2) + 1);

	strcpy_s(s, strlen(s1) + strlen(s2) + 1, s1);
	strcat_s(s, strlen(s1) + strlen(s2) + 1, s2);

	return s;
}
