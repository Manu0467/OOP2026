#pragma once
#include "NumberList.h"
#include <stdio.h>

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count>10)
	{
		return false;
	}
	else {
		this->numbers[this->count] = x;
		this->count++;
		return true;	
	}
}

void NumberList::Sort()
{
	for (int i = 0; i < this->count; i++)
	{
		int aux = this->numbers[i];
		int p = i - 1;
		while (this->numbers[p] > aux && p >= 0) {
			this->numbers[p + 1] = this->numbers[p];
			p--;
		}

		this->numbers[p + 1] = aux;
	}
}

void NumberList::Print()
{
	for (int i = 0; i < this->count; i++)
	{
		printf("%d ", this->numbers[i]);
	}
	printf("\n");
}