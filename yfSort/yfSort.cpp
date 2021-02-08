#include "pch.h"
#include "yfsort.h"
#include<stdio.h>
#include <corecrt_malloc.h>
#include <vcruntime_string.h>

void Sort::swapf(float* a, float* b)
{
	float c = *a;
	*a = *b;
	*b = c;
}

void Sort::reverseArray(int input[], size_t length)
{
	int startIndex =((length % 2 == 0) ? length / 2 : (length - 1) / 2)-1;
	float middlePosition = (length % 2 == 0) ? startIndex + .5 : length / 2-1;
	do
	{
		swap(input[startIndex], input[(int)(middlePosition * 2) - startIndex]);
	} while (startIndex--);
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

void Sort::selectionSort(int input[], size_t length, sortType sorttype)
{
	for (size_t i = 0; i < length-1; i++)
	{
		int max =i;
		for (size_t j = i+1; j < length; j++)
		{
			max = (sorttype == smallTobig) ? (input[max] <= input[j] ? max : j) : (input[max] >= input[j] ? max : j);
		}
		if(max!=i)swap(input[i], input[max]);
	}
}
void* Sort::selectionSort2(int input[], size_t length, sortType sorttype)
{
	if (length < 2)return nullptr;
	int max = 0;
	for (size_t i = 1; i < length; i++)
	{
		max = sorttype == smallTobig ? (input[max] < input[i] ? max : i) : (input[max] > input[i] ? max : i);
	}
	if(max)swap(input[0], input[max]);
	selectionSort2(input + 1, --length, sorttype);
}

void Sort::insertSort(int input[], size_t length, sortType sorttype)
{
	for (size_t preinsert = 1; preinsert < length; preinsert++)//待插入元素索引的循环
	{
		int waitForinsert = input[preinsert];
		int insertPosition = preinsert;
		for (size_t j = 0; j < preinsert; j++)//寻找插入位置
		{
			if (input[j] > input[preinsert])
			{
				insertPosition =j;
				break;
			}
		}
		for (int pushPointer = preinsert-1; pushPointer >=insertPosition; pushPointer--)//挤出一个空位
		{
			input[pushPointer + 1] = input[pushPointer];
		}
		input[insertPosition] = waitForinsert;
	}
}

