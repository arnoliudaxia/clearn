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
	void selectionSort2(int input[], size_t length, sortType);
	/// <summary>
	/// 排序的方法类似于理牌
	/// 缺点：寻找插入位置慢，移动元素消耗性能
	/// 优化：二分法；多元素同时插；数据链表；希尔排序
	/// 通过使用交换法（每次插入一个一个交换而不是把一坨移动空出来一个位子再插入）优化了代码
	/// </summary>
	void insertSort(int input[], size_t length, sortType);
	void __insertSort(int input[], size_t length, sortType sorttype);
	void heap_sort(int arr[], int len);
	//希尔排序（shell）https://www.cnblogs.com/chengxiao/p/6104371.html
	void shellSort(int input[], size_t length, sortType);
	/// <summary>
	/// 快速排序
	/// 优点是比较和交换的次数少，在许多情况下效率较高
	/// </summary>
	/// <param name="input">为了编写代码的方便，只允许从小到大排列</param>
	/// <param name="length"></param>
	void fastSort(int input[], size_t length);
};