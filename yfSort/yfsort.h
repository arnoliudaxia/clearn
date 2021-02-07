#pragma once
#define swap(a,b) (a ^= (b ^= (a ^= b)))

class Sort
{
public:
	enum sortType
	{
		smallTobig,
		bigTosmall,
	};
	int* bubbleSort(int input[], size_t length, sortType);
	int* bubbleSortLazy(int input[], size_t length, sortType);
};