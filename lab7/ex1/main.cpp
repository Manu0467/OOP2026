#include <stdio.h>

float operator"" _Kelvin(unsigned long long n) {

    return (float)n + 273.15;
}

float operator"" _Fahrenheit(unsigned long long n) {
    return (float)n - 273.15;
}


int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    return 0;
}
