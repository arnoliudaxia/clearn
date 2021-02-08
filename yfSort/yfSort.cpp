﻿#include "pch.h"
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
	if (length == 1)return;
	int startIndex =((length % 2 == 0) ? length / 2 : (length - 1) / 2)-1;
	float middlePosition = (length % 2 == 0) ? startIndex + .5 : length / 2-1;
	do
	{
		swap(input[startIndex], input[(int)(middlePosition * 2) - startIndex]);
	} while (startIndex--);
}

int* Sort::bubbleSort(int input[], size_t length, sortType sorttype)
{
	if (length == 1)goto END;
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
	END:
	return input;
}
float* Sort::bubbleSort(float input[], size_t length, sortType sorttype)
{
	if (length == 1)return input;
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
	if (length == 1)return input;
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
	if (length == 1)return input;
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
	if (length == 1)return;
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
void Sort::selectionSort2(int input[], size_t length, sortType sorttype)
{
	if (length < 2)return;
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
	if (length == 1)return;
	for (size_t preinsert = 1; preinsert < length; preinsert++)//待插入元素索引的循环
	{
		size_t j = preinsert-1;
		while (j>=0&&input[j]>input[j+1])//这里类似于冒泡的思想
		{
			swap(input[j], input[j + 1]);
			j--;
		}
	}
	if (sorttype == bigTosmall)
	{
		reverseArray(input,length);
	}
}

void max_heapify(int arr[], int start, int end)
{
	//建立父节点指标和子节点指标
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end)  //若子节点指标在范围内才做比较
	{
		if (son + 1 <= end && arr[son] < arr[son + 1])
			//先比较两个子节点大小，选择最大的
			son++;
		if (arr[dad] > arr[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
			return;
		else  //否则交换父子内容再继续子节点和孙节点比较
		{
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
void Sort::heap_sort(int input[], int len)
{
	int i;
	//初始化，i从最後一个父节点开始调整
	for (i = len / 2 - 1; i >= 0; i--)
		max_heapify(input, i, len - 1);
	//先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
	for (i = len - 1; i > 0; i--)
	{
		swap(input[0],input[i]);
		max_heapify(input, 0, i - 1);
	}
}

void Sort::shellSort(int input[], size_t length, sortType sorttype)
{
	 for(int gap=length/2;gap>0;gap/=2){
            //从第gap个元素，逐个对其所在组进行直接插入排序操作
            for(int i=gap;i<length;i++){
                int j = i;
                while(j-gap>=0 && input[j]<input[j-gap]){
                    //插入排序采用交换法
                    swap(input[j],input[j-gap]);
                    j-=gap;
                }
            }
        }
}

