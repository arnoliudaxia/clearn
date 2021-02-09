//#pragma warning(disable : 4996)

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#include "../yfSort/yfsort.h"

int main(int argNum,char args[]) {
	int a[] = { 3,5,8,1,2,9,4,7,6 };
	int b[9];
	Sort sort;
	sort.MergeSort(a, b,0,8);
	printf_s("从小到大:");
	for (auto x : a)
	{
		printf_s("%d\t",x );
	}
}