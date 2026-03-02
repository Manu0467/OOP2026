#include "Student.h"
#include<stdio.h>


void Student::SetName(const char* name) {

	Name = name;
}
const char* Student::GetName() {
	return Name;
}
void Student::SetMathematicsGrade(float n) {

	if (n>0 and n<11)
	{
		MathematicsGrade = n;
	}
	
}
float Student::GetMathematicsGrade() {
	return MathematicsGrade;
}
void Student::SetEnglishGrade(float n) {
	if (n > 0 and n < 11)
	{
		EnglishGrade = n;
	}
}
float Student::GetEnglishGrade() {
	return EnglishGrade;
}
void Student::SetHistoryGrade(float n) {
	if (n > 0 and n < 11)
	{
		HistoryGrade = n;
	}
}
float Student::GetHistoryGrade() {
	return HistoryGrade;
}
float Student::GetAverageGrade() {
	return (MathematicsGrade + EnglishGrade + HistoryGrade) / 3;
}
