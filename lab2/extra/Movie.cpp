#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include<ctime>

void Movie::set_name(const char* n) {
	Name = n;
}

const char* Movie::get_name() {

	return Name;
}
void Movie::set_year(int year) {
	ReleaseYear = year;
}

int Movie::get_year() {
	return ReleaseYear;
}

void Movie::set_length(int n) {
	Length = n;
}


int Movie::get_length() {
	return Length;
}

void Movie::set_score(double s) {

	IMDBscore = s;
}
double Movie::get_score() {
	return IMDBscore;
}

int  Movie::get_passed_years() {

	std::time_t t = std::time(nullptr);
	std::tm* acum = std::localtime(&t);
	int currentYear = 1900 + acum->tm_year;

return currentYear - ReleaseYear;
}