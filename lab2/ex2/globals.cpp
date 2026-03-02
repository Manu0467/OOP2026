#include"globals.h"
#include<stdio.h>
#include<fstream>
int CompareMathematicsGrades(Student student1, Student student2) {

	if (student1.GetMathematicsGrade() > student2.GetMathematicsGrade())
	{
		return 1;
	}
	else if (student1.GetMathematicsGrade() < student2.GetMathematicsGrade())
	{
		return -1;
	}
	else {
		return 0;
	}

}
int CompareEnglishGrades(Student student1, Student student2) {

	if (student1.GetEnglishGrade() > student2.GetEnglishGrade())
	{
		return 1;
	}
	else if (student1.GetEnglishGrade() < student2.GetEnglishGrade())
	{
		return -1;
	}
	else {
		return 0;
	}

}
int CompareHistoryGrades(Student student1, Student student2) {

	if (student1.GetHistoryGrade() > student2.GetHistoryGrade())
	{
		return 1;
	}
	else if (student1.GetHistoryGrade() < student2.GetHistoryGrade())
	{
		return -1;
	}
	else {
		return 0;
	}

}
int CompareAverageGrade(Student student1, Student student2) {

	if (student1.GetAverageGrade() > student2.GetAverageGrade())
	{
		return 1;
	}
	else if (student1.GetAverageGrade() < student2.GetAverageGrade())
	{
		return -1;
	}
	else {
		return 0;
	}

}
int CompareStudentsName(Student student1, Student student2) {
	if ((strcmp(student1.GetName(), student2.GetName()) > 0) && strlen(student1.GetName()) > strlen(student2.GetName()))
	{
		return 1;
	}
	if (strlen(student1.GetName()) < strlen(student2.GetName()))
	{
		return -1;
	}
	if (strlen(student1.GetName()) == strlen(student2.GetName()))
	{
		return 0;

	}
}
