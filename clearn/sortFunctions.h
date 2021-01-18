#pragma once
#define swap(a,b) a ^= (b ^= (a ^= b));

enum sortType
{
	smallTobig,
	bigTosmall,
};
int* bubbleSort(int input[], size_t length, sortType sorttype);
int* bubbleSortLazy(int input[], size_t length, sortType sorttype);