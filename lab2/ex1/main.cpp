#pragma once
#include "NumberList.h"
#include <stdio.h>

void main()
{
    NumberList list;
    list.Init();
    list.Add(10);
    list.Add(5);
    list.Add(20);
    list.Print();
    list.Sort();
    list.Print();
}