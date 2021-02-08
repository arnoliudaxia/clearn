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
	void reverseArray(int input[], size_t length);
	int* bubbleSort(int input[], size_t length, sortType);
	float* bubbleSort(float input[], size_t length, sortType);
	int* bubbleSortLazy(int input[], size_t length, sortType);
	float* bubbleSortLazy(float input[], size_t length, sortType);
	void selectionSort(int input[], size_t length, sortType);
	void* selectionSort2(int input[], size_t length, sortType);
	void insertSort(int input[], size_t length, sortType);
};