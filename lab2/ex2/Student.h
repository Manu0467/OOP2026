#pragma once
class Student
{
	const char* Name;
	float MathematicsGrade = 0;
	float EnglishGrade = 0;
	float HistoryGrade = 0;

public:
	void SetName(const char* name);
	const char* GetName();

	void SetMathematicsGrade(float n);
	float GetMathematicsGrade();

	void SetEnglishGrade(float n);
	float GetEnglishGrade();

	void SetHistoryGrade(float n);
	float GetHistoryGrade();

	float GetAverageGrade();
};

