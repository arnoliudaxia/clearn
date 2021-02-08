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
	/// ����ķ�������������
	/// ȱ�㣺Ѱ�Ҳ���λ�������ƶ�Ԫ����������
	/// �Ż������ַ�����Ԫ��ͬʱ�壻��������ϣ������
	/// ͨ��ʹ�ý�������ÿ�β���һ��һ�����������ǰ�һ���ƶ��ճ���һ��λ���ٲ��룩�Ż��˴���
	/// </summary>
	void insertSort(int input[], size_t length, sortType);
	void __insertSort(int input[], size_t length, sortType sorttype);
	void heap_sort(int arr[], int len);
	//ϣ������shell��https://www.cnblogs.com/chengxiao/p/6104371.html
	void shellSort(int input[], size_t length, sortType);
};