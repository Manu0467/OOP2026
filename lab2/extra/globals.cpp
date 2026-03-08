#include "Movie.h"
#include"globals.h"
#include<stdio.h>
#include<cstring>

int movie_compare_name(Movie movie1, Movie movie2) {

	if (strlen(movie1.get_name()) > strlen(movie1.get_name()))
	{
		return 1;
	}
	else if (strlen(movie1.get_name()) < strlen(movie1.get_name()))
	{
		return -1;
	}
	else {
		return 0;
	}

}

int movie_compare_year(Movie movie1, Movie movie2) {

	if (movie1.get_year() > movie2.get_year())
	{
		return 1;
	}
	else if (movie1.get_year() < movie2.get_year())
	{
		return -1;
	}
	else {
		return 0;
	}
}

int movie_compare_score(Movie movie1, Movie movie2) {

	if (movie1.get_score() > movie2.get_score())
	{
		return 1;
	}
	else if (movie1.get_score() < movie2.get_score())
	{
		return -1;
	}
	else {
		return 0;
	}
}

int movie_compare_length(Movie movie1, Movie movie2) {

	if (movie1.get_length() > movie2.get_length())
	{
		return 1;
	}
	else if (movie1.get_length() < movie2.get_length())
	{
		return -1;
	}
	else {
		return 0;
	}
}

int movie_compare_passed_years(Movie movie1, Movie movie2) {

	if (movie1.get_passed_years() > movie2.get_passed_years())
	{
		return 1;
	}
	else if (movie1.get_passed_years() < movie2.get_passed_years())
	{
		return -1;
	}
	else {
		return 0;
	}
}