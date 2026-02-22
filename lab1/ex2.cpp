#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>



int main()
{
    char s[400];
    char* p;
    char* v[100];
    int n = 0;

    scanf("%399[^\n]s", s);

    p = strtok(s, " ");

    while (p != NULL) {

    v[n] = p;
    n++;
    p= strtok(NULL, " ");
    }

    for (int i = 0; i < n; i++)
    {
        char* aux = v[i];
        int p = i - 1;
        while (p >= 0 && (strcmp(v[p], aux) > 0) && (strlen(v[p]) > strlen(aux)) ) {
            v[p + 1] = v[p];
            p--;
        }
        v[p+1] = aux;

    }

    for (int i = n-1; i >=0; i--)
    {
        printf("%s\n", v[i]);
    }

    


   

    return 0;
}
