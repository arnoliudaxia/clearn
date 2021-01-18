#include<stdio.h>
#include <corecrt_malloc.h>
#include "sortFunctions.h"

int* bubbleSort(int input[], size_t length, sortType sorttype)
{
	//�Ż��㷨�������� n-1 �ֱȽ�
	for (int i = 0; i < length - 1; i++)
	{
		bool isSorted = 1;  //����ʣ�µ�Ԫ���Ѿ��������
		for (int j = 0; j < length - 1 - i; j++) {
			bool dosort = (sorttype == smallTobig) ? input[j] > input[j + 1] : input[j] < input[j + 1];
			if (dosort) {
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				isSorted = 0;  //һ����Ҫ��������Ԫ�أ���˵��ʣ�µ�Ԫ��û�������
			}
		}
		if (isSorted) break; //���û�з���������˵��ʣ�µ�Ԫ���Ѿ��������
	}
	return input;
}
int* bubbleSortLazy(int input[], size_t length, sortType sorttype)
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (size_t i = 0; i < length - 1; i++)
		{
			bool op = input[i] < input[i + 1];
			if (sorttype == smallTobig && input[i] != input[i + 1])op = !op;
			if (op) {
				auto temp = input[i];
				input[i] = input[i + 1];
				input[i + 1] = temp;
				flag = true;
			}
		}
	}
	return (input);
}