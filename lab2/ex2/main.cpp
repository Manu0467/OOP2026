#pragma once
#include "Student.h"
#include <stdio.h>
#include"globals.h"



void main()
{
    Student student1, student2;

    student1.SetName("Mihai");
    student2.SetName("Corina");

    student1.SetEnglishGrade(6.2);
    student2.SetEnglishGrade(9.3);

    student1.SetHistoryGrade(8.5);
    student2.SetHistoryGrade(7.5);

    student1.SetMathematicsGrade(7.2);
    student2.SetMathematicsGrade(9.2);

    float avgs1 = student1.GetAverageGrade(),
          avgs2 = student2.GetAverageGrade();
    const char* name1 = student1.GetName();
    const char* name2 = student2.GetName();

    printf("Average grade %s: %f\n", name1, avgs1);
    printf("Average grade %s: %f\n",name2, avgs2);
    printf("English grades comparison: %d\n", CompareEnglishGrades(student1, student2));
    printf("History` grades comparison: %d\n", CompareHistoryGrades(student1, student2));
    printf("Mathematics grades comparison : % d\n", CompareMathematicsGrades(student1, student2));
    printf("Average grade comparison: %d\n", CompareAverageGrade(student1, student2));
    printf("Name comparison: %d\n", CompareStudentsName(student1, student2));



   
}