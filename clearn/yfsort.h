#pragma once
#include <vector>
//#define swap(a,b) (a ^= (b ^= (a ^= b))) //只能交换整型

using namespace std;

class Sort
{
public:
	enum sortType
	{
		smallTobig,
		bigTosmall,
	};
	//一些基础算法
	void swapf(float* a, float* b);
	void reverseArray(int input[], size_t length);
	//冒泡排序
	void bubbleSort(vector<int> &input, sortType sorttype=smallTobig);
	[[deprecated("Old C style")]]
	int* c_bubbleSort(int input[], size_t length, sortType);
	[[deprecated("Old C style")]]
	float* bubbleSort(float input[], size_t length, sortType);
	[[deprecated]]
	int* bubbleSortLazy(int input[], size_t length, sortType);
	[[deprecated]]
	float* bubbleSortLazy(float input[], size_t length, sortType);
	//选择排序
	void selectionSort(int input[], size_t length, sortType);
	void selectionSort2(int input[], size_t length, sortType);
	/// <summary>插入排序
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
	/// <summary>
	/// 归并排序
	/// https://www.cnblogs.com/chengxiao/p/6194356.html
	/// 归并排序是稳定排序，它也是一种十分高效的排序，能利用完全二叉树特性的排序一般性能都不会太差。
	/// 每次合并操作的平均时间复杂度为O(n)，而完全二叉树的深度为|log2n|。总的平均时间复杂度为O(nlogn)。而且，归并排序的最好，最坏，平均时间复杂度均为O(nlogn)。
	/// </summary>
	/// <param name="sourceArr"></param>
	/// <param name="tempArr"></param>
	/// <param name="startIndex"></param>
	/// <param name="endIndex"></param>
	void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex);
	/// <summary>
	/// 技计数排序
	/// 以空间换取时间
	/// 原理：把每个元素统计有多少个，然后一个个按大小顺序释放出来
	/// 优点：时间复杂度为Ο(n+k)（其中k是整数的范围），快于任何比较排序算法。
	/// 但是必须满足一下两个限制条件：
	/// 元素都为整数
	/// 元素的值域较小
	/// </summary>
	/// <param name="data"></param>
	/// <param name="n"></param>
	void CountSort(int data[], int n);
	
};