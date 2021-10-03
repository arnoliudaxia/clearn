#pragma warning(disable : 4996)

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#include "yfsort.h"
#include "yflinktable.h"
#include <vector>
#include <iostream>
#include <algorithm>

int main(int argNum,char args[]) {
	using namespace std;

	//sort alogrithm test template
	//vector<int> a = { 3,5,8,1,2,9,4,7,6 };
	//Sort mysort;
	////int b[9];
	//mysort.bubbleSort(a);
	//sort(a.begin(), a.end());
	//for (auto x : a)
	//{
	//	cout << x << "\t";
	//}
	
	//linktable alogrithm test template
	using namespace cpluslinktable;
	Linktable<Node<int>,int> linktable(10);
	orderLinkTable<> orderlinktable(1);
	linktable.addNode(20);
	linktable.logNodes();

	orderlinktable.addNode(2);
	orderlinktable.logNodes();


	

}