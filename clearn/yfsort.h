#pragma once
#include <vector>
//#define swap(a,b) (a ^= (b ^= (a ^= b))) //ֻ�ܽ�������

using namespace std;

class Sort
{
public:
	enum sortType
	{
		smallTobig,
		bigTosmall,
	};
	//һЩ�����㷨
	void swapf(float* a, float* b);
	void reverseArray(int input[], size_t length);
	//ð������
	void bubbleSort(vector<int> &input, sortType sorttype=smallTobig);
	[[deprecated("Old C style")]]
	int* c_bubbleSort(int input[], size_t length, sortType);
	[[deprecated("Old C style")]]
	float* bubbleSort(float input[], size_t length, sortType);
	[[deprecated]]
	int* bubbleSortLazy(int input[], size_t length, sortType);
	[[deprecated]]
	float* bubbleSortLazy(float input[], size_t length, sortType);
	//ѡ������
	void selectionSort(int input[], size_t length, sortType);
	void selectionSort2(int input[], size_t length, sortType);
	/// <summary>��������
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
	/// <summary>
	/// ��������
	/// �ŵ��ǱȽϺͽ����Ĵ����٣�����������Ч�ʽϸ�
	/// </summary>
	/// <param name="input">Ϊ�˱�д����ķ��㣬ֻ�����С��������</param>
	/// <param name="length"></param>
	void fastSort(int input[], size_t length);
	/// <summary>
	/// �鲢����
	/// https://www.cnblogs.com/chengxiao/p/6194356.html
	/// �鲢�������ȶ�������Ҳ��һ��ʮ�ָ�Ч��������������ȫ���������Ե�����һ�����ܶ�����̫�
	/// ÿ�κϲ�������ƽ��ʱ�临�Ӷ�ΪO(n)������ȫ�����������Ϊ|log2n|���ܵ�ƽ��ʱ�临�Ӷ�ΪO(nlogn)�����ң��鲢�������ã����ƽ��ʱ�临�ӶȾ�ΪO(nlogn)��
	/// </summary>
	/// <param name="sourceArr"></param>
	/// <param name="tempArr"></param>
	/// <param name="startIndex"></param>
	/// <param name="endIndex"></param>
	void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex);
	/// <summary>
	/// ����������
	/// �Կռ任ȡʱ��
	/// ԭ����ÿ��Ԫ��ͳ���ж��ٸ���Ȼ��һ��������С˳���ͷų���
	/// �ŵ㣺ʱ�临�Ӷ�Ϊ��(n+k)������k�������ķ�Χ���������καȽ������㷨��
	/// ���Ǳ�������һ����������������
	/// Ԫ�ض�Ϊ����
	/// Ԫ�ص�ֵ���С
	/// </summary>
	/// <param name="data"></param>
	/// <param name="n"></param>
	void CountSort(int data[], int n);
	
};