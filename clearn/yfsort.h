#pragma once
#include <vector>
//#define swap(a,b) (a ^= (b ^= (a ^= b))) //ֻ�ܽ�������

using namespace std;

template<class T=int>
class Sort
{
public:
	enum sortType
	{
		smallTobig,
		bigTosmall,
	};
	//һЩ�����㷨
	void swapTwo(T& a, T& b) {
		T c = a;
		a = b;
		b = c;
	};
	void swapTwo(T* a, T* b) { swapTwo(*a, *b); };
	void c_reverseArray(int input[], size_t length);
	//ð������
	void bubbleSort(vector<int> &input, sortType sorttype=smallTobig);
	[[deprecated("Old C style")]]
	void c_bubbleSort(T input[], size_t length, sortType);
	[[deprecated]]
	T* bubbleSortLazy(T input[], size_t length, sortType);
	//ѡ������
	void selectionSort(T input[], size_t length, sortType);
	void selectionSort2(T input[], size_t length, sortType);
	/// <summary>
	/// ��������
	/// ����ķ�������������
	/// ȱ�㣺Ѱ�Ҳ���λ�������ƶ�Ԫ����������
	/// �Ż������ַ�����Ԫ��ͬʱ�壻��������ϣ������
	/// ͨ��ʹ�ý�������ÿ�β���һ��һ�����������ǰ�һ���ƶ��ճ���һ��λ���ٲ��룩�Ż��˴���
	/// </summary>
	void insertSort(T input[], size_t length, sortType);
	void __insertSort(T input[], size_t length, sortType sorttype);
	//������
	void heap_sort(int arr[], int len);
	//ϣ������shell��https://www.cnblogs.com/chengxiao/p/6104371.html
	void shellSort(int input[], size_t length, sortType);


	/// <summary>
	/// ��������
	/// �ŵ��ǱȽϺͽ����Ĵ����٣�����������Ч�ʽϸ�
	/// </summary>
	/// <param name="input">Ϊ�˱�д����ķ��㣬ֻ�����С��������</param>
	/// <param name="length"></param>
	void fastSort(int input[], int length);
	//�����ȹ�ģ�����飬һ��������һ������
	void fastSortOneFollow(int input[], size_t length, int other[]);

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
	void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex,bool Recursion=1);


	/// <summary>
	/// ��������
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