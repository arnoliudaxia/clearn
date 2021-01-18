#pragma warning(disable : 4996)
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "sortFunctions.h"
int main(void)
{
    int aa[] = { 1,2,5,3,64,3 };
    bubbleSort(aa, 6, smallTobig);
    NULL;
    return 0;
}