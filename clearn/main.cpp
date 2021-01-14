#pragma warning(disable : 4996)
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "sortFunctions.h"

int main(void)
{
    int ii[] = { 2,3,1,5,3,7 }; 
    int* result = bubbleSortLazy(ii, 5, bigTosmall);
    for (size_t i = 0; i < 5; i++,result++)
    {
        printf("%d", *result);
    }
   // for(int x: result)
   
    return 0;
}