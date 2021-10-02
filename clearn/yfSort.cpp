#include "yfsort.h"
#include<stdio.h>
#include <corecrt_malloc.h>
#include <vcruntime_string.h>

void Sort::swapf(float* a, float* b)
{
	float c = *a;
	*a = *b;
	*b = c;
}

void Sort::reverseArray(int input[], size_t length)
{
	if (length == 1)return;
	int startIndex =((length % 2 == 0) ? length / 2 : (length - 1) / 2)-1;
	float middlePosition = (length % 2 == 0) ? startIndex + .5 : length / 2-1;
	do
	{
		swap(input[startIndex], input[(int)(middlePosition * 2) - startIndex]);
	} while (startIndex--);
}

template<class T>
void swap(T* x,T* y)
{
	T temp = *x;
	*x = *y;
	*y = temp;
}
//冒泡排序
void Sort::bubbleSort(vector<int> &input, sortType sorttype)
{
	int length = input.size();
	if (length == 1)goto END;
	//优化算法：最多进行 n-1 轮比较
	for (int i = 0; i < length - 1; i++)
	{
		bool isSorted = 1;  //假设剩下的元素已经排序好了
		for (int j = 0; j < length - 1 - i; j++) {
			bool dosort = (sorttype == smallTobig) ? input[j] > input[j + 1] : input[j] < input[j + 1];
			if (dosort) {
				swap(input[j], input[j + 1]);
				isSorted = 0;  //一旦需要交换数组元素，就说明剩下的元素没有排序好
			}
		}
		if (isSorted) break; //如果没有发生交换，说明剩下的元素已经排序好了
	}
END:
	return;
}
int* Sort::c_bubbleSort(int input[], size_t length, sortType sorttype)
{
	if (length == 1)goto END;
	//优化算法：最多进行 n-1 轮比较
	for (int i = 0; i < length - 1; i++)
	{
		bool isSorted = 1;  //假设剩下的元素已经排序好了
		for (int j = 0; j < length - 1 - i; j++) {
			bool dosort = (sorttype == smallTobig) ? input[j] > input[j + 1] : input[j] < input[j + 1];
			if (dosort) {
				swap(input[j], input[j + 1]);
				isSorted = 0;  //一旦需要交换数组元素，就说明剩下的元素没有排序好
			}
		}
		if (isSorted) break; //如果没有发生交换，说明剩下的元素已经排序好了
	}
	END:
	return input;
}
float* Sort::bubbleSort(float input[], size_t length, sortType sorttype)
{
	if (length == 1)return input;
	//优化算法：最多进行 n-1 轮比较
	for (int i = 0; i < length - 1; i++)
	{
		bool isSorted = 1;  //假设剩下的元素已经排序好了
		for (int j = 0; j < length - 1 - i; j++) {
			bool dosort = (sorttype == smallTobig) ? input[j] > input[j + 1] : input[j] < input[j + 1];
			if (dosort) {
				swapf(input+j, input+j + 1);
				isSorted = 0;  //一旦需要交换数组元素，就说明剩下的元素没有排序好
			}
		}
		if (isSorted) break; //如果没有发生交换，说明剩下的元素已经排序好了
	}
	return input;
}
int* Sort::bubbleSortLazy(int input[], size_t length, sortType sorttype)
{
	if (length == 1)return input;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (size_t i = 0; i < length - 1; i++)
		{
			bool op = input[i] < input[i + 1];
			if (sorttype == smallTobig && input[i] != input[i + 1])op = !op;
			if (op) {
				swap(input[i], input[i + 1]);
				flag = true;
			}
		}
	}
	return (input);
}
float* Sort::bubbleSortLazy(float input[], size_t length, sortType sorttype)
{
	if (length == 1)return input;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (size_t i = 0; i < length - 1; i++)
		{
			bool op = input[i] < input[i + 1];
			if (sorttype == smallTobig && input[i] != input[i + 1])op = !op;
			if (op) {
				swapf(input+i, &input[i + 1]);
				flag = true;
			}
		}
	}
	return (input);
}

void Sort::selectionSort(int input[], size_t length, sortType sorttype)
{
	if (length == 1)return;
	for (size_t i = 0; i < length-1; i++)
	{
		int max =i;
		for (size_t j = i+1; j < length; j++)
		{
			max = (sorttype == smallTobig) ? (input[max] <= input[j] ? max : j) : (input[max] >= input[j] ? max : j);
		}
		if(max!=i)swap(input[i], input[max]);
	}
}
void Sort::selectionSort2(int input[], size_t length, sortType sorttype)
{
	if (length < 2)return;
	int max = 0;
	for (size_t i = 1; i < length; i++)
	{
		max = sorttype == smallTobig ? (input[max] < input[i] ? max : i) : (input[max] > input[i] ? max : i);
	}
	if(max)swap(input[0], input[max]);
	selectionSort2(input + 1, --length, sorttype);
}

//使用交换法
void Sort::insertSort(int input[], size_t length, sortType sorttype)
{
	if (length == 1)return;
	for (size_t preinsert = 1; preinsert < length; preinsert++)//待插入元素索引的循环
	{
		size_t j = preinsert-1;
		while (j>=0&&input[j]>input[j+1])//这里类似于冒泡的思想
		{
			swap(input[j], input[j + 1]);
			j--;
		}
	}
	if (sorttype == bigTosmall)
	{
		reverseArray(input,length);
	}
}
//使用插入法
void Sort::__insertSort(int input[], size_t length, sortType sorttype)
{
	if (length == 1)return;
	for (size_t preinsert = 1; preinsert < length; preinsert++)//待插入元素索引的循环
	{
		int waitForinsert = input[preinsert];//把待插入的数据先储存起来，后面要覆盖
		int insertPosition = preinsert;//首先假定不用插入
		for (size_t j = 0; j < preinsert; j++)//寻找插入位置
		{
			if (input[j] > input[preinsert])
			{
				insertPosition = j;
				break;
			}
		}
		for (int pushPointer = preinsert - 1; pushPointer >= insertPosition; pushPointer--)//挤出一个空位
		{
			input[pushPointer + 1] = input[pushPointer];
		}
		input[insertPosition] = waitForinsert;
	}
	if (sorttype == bigTosmall)
	{
		reverseArray(input, length);
	}
}
void max_heapify(int arr[], int start, int end)
{
	//建立父节点指标和子节点指标
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end)  //若子节点指标在范围内才做比较
	{
		if (son + 1 <= end && arr[son] < arr[son + 1])
			//先比较两个子节点大小，选择最大的
			son++;
		if (arr[dad] > arr[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
			return;
		else  //否则交换父子内容再继续子节点和孙节点比较
		{
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
void Sort::heap_sort(int input[], int len)
{
	int i;
	//初始化，i从最後一个父节点开始调整
	for (i = len / 2 - 1; i >= 0; i--)
		max_heapify(input, i, len - 1);
	//先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
	for (i = len - 1; i > 0; i--)
	{
		swap(input[0],input[i]);
		max_heapify(input, 0, i - 1);
	}
}

void Sort::shellSort(int input[], size_t length, sortType sorttype)
{
	 for(int gap=length/2;gap>0;gap/=2){//这里增量取an+1=an/2（shell本人的建议）并非是最好的选择
            //从第gap个元素，逐个对其所在组进行直接插入排序操作
            for(int i=gap;i<length;i++){
                int j = i;
                while(j-gap>=0 && input[j]<input[j-gap]){
                    //插入排序采用交换法
                    swap(input[j],input[j-gap]);
                    j-=gap;
                }
            }
        }
}

////1）采用更合理的基准数（中心轴），减少递归的深度。从数列中选取多个数，取中间数。
//2）结合插入排序，区间在10个元素之内采用插入排序，效率更高。
void Sort::fastSort(int input[], size_t length)
{
	if (length < 2)return;
	int pivot = input[length - 1];//令pivot为数组最右侧的元素
	int L = 0, R = length - 2;//定义L，R标记
	moveTag:
	while (input[L] < pivot)L++;//移动L标签（寻找大于pivot的元素）
	if (L == length - 1)goto END;//如果L到达了pivot（L碰到R不会停止）
	while (input[R] >= pivot)//左移R（寻找小于pivot的元素）
	{
		if (L == R)
		{
			swap(input[R], input[length - 1]);//如果LR已经碰面，就认为排序完成
			goto END;
		}
		R--;
	}
	swap(input[L], input[R]);//将小的扔到右边，大的扔到左边
	goto moveTag;//如果LR没有碰面，就继续
END:
	fastSort(input, L);
	fastSort(input + L + 1, length - L - 1);
}

void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		if (sourceArr[i] > sourceArr[j])
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];
	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}
//内部使用递归
void Sort::MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex, bool Recursion)
{
	if (startIndex >= endIndex) return;
		int midIndex = startIndex + (endIndex - startIndex) / 2;//避免溢出int
		MergeSort(sourceArr, tempArr, startIndex, midIndex);
		MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
		Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
	}

//使用循环代替递归
template <typename T>
void merge_sort(vector<T> a) {
	int n = a.size();
	for (int seg = 1; seg < n; seg = seg + seg)
		for (int start = 0; start < n - seg; start += seg + seg)
			merge(a, start, start + seg - 1, std::min(start + seg + seg - 1, n - 1));
}

void Sort::CountSort(int data[], int n)
{
	int i, j, count, * data_p, temp;
	data_p = (int*)malloc(sizeof(int) * n);
	for (i = 0;i < n;i++)//初始化data_p
		data_p[i] = 0;
	for (i = 0;i < n;i++)
	{
		count = 0;
		for (j = 0;j < n;j++)//扫描待排序数组
			if (data[j] < data[i])//统计比data[i]值小的值的个数
				count++;
		while (data_p[count] != 0)//对于相等非0的数据，应向后措一位。数据为0时，因数组data_p被初始化为0，故不受影响。
		/* 注意此处应使用while循环进行判断，若用if条件则超过三个重复值后有0出现 */
			count++;
		data_p[count] = data[i];//存放到data_p中的对应位置
	}
	//用于检查当有多个数相同时的情况
	i = 0, j = n;
	while (i < j)
	{
		if (data_p[i] == 0)
		{
			temp = i - 1;
			data_p[i] = data_p[temp];
		}//of if
		i++;
	}//of  while
	for (i = 0;i < n;i++)//把排序完的数据复制到data中	
		data[i] = data_p[i];
	delete(data_p);//释放data_p
}