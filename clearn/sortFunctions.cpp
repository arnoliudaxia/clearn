#include<stdio.h>
#include <corecrt_malloc.h>
#include "sortFunctions.h"
struct dataInt
{
	int length;
	int data[0];
};

void initdataint(int input[], size_t length)
{
	;
}
auto bubbleSort(int input[])
{

	return 0;
}
int* bubbleSortLazy(int input[], size_t length, sortType sorttype)
{

	dataInt* dataint = (dataInt*)malloc(sizeof(dataInt) + sizeof(int) * length);
	for (size_t i = 0; i < length; i++)
	{
		dataint->data[i] = input[i];
	}
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (size_t i = 0; i < length - 1; i++)
		{
			bool op;
			if (dataint->data[i] < dataint->data[i + 1])op = true;
			else op = false;
			if (sorttype == smallTobig)op = !op;
			if (op) {
				auto temp = dataint->data[i];
				dataint->data[i] = dataint->data[i + 1];
				dataint->data[i + 1] = temp;
				flag = true;
			}
		}
	}
	return (dataint->data);
}