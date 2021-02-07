//#pragma warning(disable : 4996)

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#include "../yfLibrary/sort.h"

int main(int argNum,char args[]) {
	int a[] = { 2,2,4,1,5,3,3 };
	Sort sort;
	sort.bubbleSortLazy(a, 7, Sort::bigTosmall);
	
	for (auto x:a)
	{
		printf_s("%d", x);
	}
}