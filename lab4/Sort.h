#pragma once
#include <stdio.h>
#include <varargs.h>
#include <string>
#include <vector>

class Sort
{
private:
	int counter;
	std::vector<int> lista;
public:
    Sort(int elements_count, int minimum, int maximum);
    Sort(std::initializer_list<int> list);
    Sort(std::vector<int> v, int cnt);
    Sort(int cnt, ...);
    Sort(std::string list);

    
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);

};

