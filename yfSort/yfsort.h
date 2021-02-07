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
	void swapf(float* a, float* b);
	int* bubbleSort(int input[], size_t length, sortType);
	float* bubbleSort(float input[], size_t length, sortType);
	int* bubbleSortLazy(int input[], size_t length, sortType);
	float* bubbleSortLazy(float input[], size_t length, sortType);
};