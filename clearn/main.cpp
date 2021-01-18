#pragma warning(disable : 4996)
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "sortFunctions.h"
#define swap(a,b) a ^= (b ^= (a ^= b));
int main(void)
{
    int a = 1, b = 2;
   /* a ^= b;
    b ^= a;
    a ^= b;*/
    swap(a, b);
    printf("a=%d,b=%d", a, b);
    return 0;
}