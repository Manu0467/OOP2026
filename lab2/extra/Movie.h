#pragma once
class Movie
{
	const char* Name;
	int ReleaseYear;
	int IMDBscore;
	int Length;

public:
	void set_name(const char* n);
	const char* get_name();

	void set_year(int n);
	int  get_year();

	void set_length(int n);
	int get_length();

	void set_score(double n);
	double get_score();

	int get_passed_years();
};

