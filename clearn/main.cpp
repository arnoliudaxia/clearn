//#pragma warning(disable : 4996)

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#include "../yfSort/yfsort.h"

int main(int argNum,char args[]) {
	float a[] = { 2,2,4,1,5,3,3 };
	Sort sort;
	sort.bubbleSort(a, 7, Sort::bigTosmall);
	
	for (auto x:a)
	{
		printf_s("%.2f\t", x);
	}
}