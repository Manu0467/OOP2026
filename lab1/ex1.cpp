#include <stdio.h>
#include <fstream>
using namespace std;

ifstream fin("in.txt");

int main() {

    int n, sum = 0;

    while (fin >> n)
    {
        sum += n;
    }

    printf("%d", sum);


    return 0;
}