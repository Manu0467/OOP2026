#include "MovieSeries.h"
#include"Movie.h"
#include"globals.h"
#include<stdio.h>

void MovieSeries::init() {
	count = 0;
}

void MovieSeries::add(Movie* movie) {

	if (count < 16) {
		series[count] = movie;
		count++;
	}
	else {
		printf("List full! Start a new one!");
	}
}
void MovieSeries::sort() {

	for (int i = 1; i < count; i++)
	{
		Movie* aux = series[i];
		int p = i - 1;
		while (p >= 0 && series[p]->get_passed_years() > aux->get_passed_years()) {

			series[p + 1] = series[p];
			p--;
		}
		series[p+1] = aux;
	}

}

void MovieSeries::print() {


	for (int i = count-1; i >= 0 ; i--)
	{

printf(
	R"(
name        : %s
year        : %d
score       : %f
length      : %d
passed years: %d
)",
series[i]->get_name(),
series[i]->get_year(),
series[i]->get_score(),
series[i]->get_length(),
series[i]->get_passed_years());
	}

}
