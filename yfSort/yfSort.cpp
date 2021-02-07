#include "pch.h"
#include "yfsort.h"
#include<stdio.h>

void Sort::swapf(float* a, float* b)
{
	float c = *a;
	*a = *b;
	*b = c;
}

int* Sort::bubbleSort(int input[], size_t length, sortType sorttype)
{
	//优化算法：最多进行 n-1 轮比较
	for (int i = 0; i < length - 1; i++)
	{
		bool isSorted = 1;  //假设剩下的元素已经排序好了
		for (int j = 0; j < length - 1 - i; j++) {
			bool dosort = (sorttype == smallTobig) ? input[j] > input[j + 1] : input[j] < input[j + 1];
			if (dosort) {
				swap(input[j], input[j + 1]);
				isSorted = 0;  //一旦需要交换数组元素，就说明剩下的元素没有排序好
			}
		}
		if (isSorted) break; //如果没有发生交换，说明剩下的元素已经排序好了
	}
	return input;
}
float* Sort::bubbleSort(float input[], size_t length, sortType sorttype)
{
	//优化算法：最多进行 n-1 轮比较
	for (int i = 0; i < length - 1; i++)
	{
		bool isSorted = 1;  //假设剩下的元素已经排序好了
		for (int j = 0; j < length - 1 - i; j++) {
			bool dosort = (sorttype == smallTobig) ? input[j] > input[j + 1] : input[j] < input[j + 1];
			if (dosort) {
				swapf(input+j, input+j + 1);
				isSorted = 0;  //一旦需要交换数组元素，就说明剩下的元素没有排序好
			}
		}
		if (isSorted) break; //如果没有发生交换，说明剩下的元素已经排序好了
	}
	return input;
}
int* Sort::bubbleSortLazy(int input[], size_t length, sortType sorttype)
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (size_t i = 0; i < length - 1; i++)
		{
			bool op = input[i] < input[i + 1];
			if (sorttype == smallTobig && input[i] != input[i + 1])op = !op;
			if (op) {
				swap(input[i], input[i + 1]);
				flag = true;
			}
		}
	}
	return (input);
}
float* Sort::bubbleSortLazy(float input[], size_t length, sortType sorttype)
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (size_t i = 0; i < length - 1; i++)
		{
			bool op = input[i] < input[i + 1];
			if (sorttype == smallTobig && input[i] != input[i + 1])op = !op;
			if (op) {
				swapf(input+i, &input[i + 1]);
				flag = true;
			}
		}
	}
	return (input);
}
