#pragma once
#include"Movie.h"
class MovieSeries
{
	Movie* series[16];
	int count;

public:
	void init();
	void sort();
	void print();
	void add(Movie* movie);

};

