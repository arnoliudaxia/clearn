//#pragma warning(disable : 4996)

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#include "../yfSort/yfsort.h"

int main(int argNum,char args[]) {
	int a[] = { 2,2,4,1,5,3,3,9 };
	Sort sort;
	sort.reverseArray(a, 8);
	for (auto x : a)
	{
		printf_s("%d\t",x );
	}
}