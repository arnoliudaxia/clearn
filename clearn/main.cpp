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

[[deprecated]]
void TriassicPeriod() {
	std::clog << "Triassic Period: [251.9 - 208.5] million years ago.\n";
}

[[deprecated("Use NeogenePeriod() instead.")]]
void JurassicPeriod() {
	std::clog << "Jurassic Period: [201.3 - 152.1] million years ago.\n";
}
int main(int argNum,char args[]) {
	using namespace std;
	//ÅÅÐòËã·¨²âÊÔÄ£°å
	//vector<int> a = { 3,5,8,1,2,9,4,7,6 };
	//Sort mysort;
	////int b[9];
	//mysort.bubbleSort(a);
	//sort(a.begin(), a.end());
	//for (auto x : a)
	//{
	//	cout << x << "\t";
	//}
	
	using namespace mylinktable;
	Linktable<Node> linktable(10);
	//Linktable::Node* head= linktable.initializeNode(10);
	//linktable.addNode(999, head);
	//printf("%d\n",linktable.search(10,head));
	//linktable.logNodes(head);



}