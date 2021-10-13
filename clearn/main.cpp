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
#include "binaryTreePrefab.h"
//#include "myalgorithm.cpp"

int main(int argNum,char args[]) {
	using namespace std;

	//sort alogrithm test template
	vector<int> a= { 3,5,8,1,2,9,4,7,6 };

	Sort mysort;
	//int b[9];

	/*sort(a.begin(), a.end());
	for (auto x : a)
	{
		cout << x << "\t";
	}*/
	
	//linktable alogrithm test template
	/*using namespace cpluslinktable;
	Linktable<Node<int>,int> linktable(10);
	linktable.addNode(20);
	Linktable<Node<int>, int> linktable2(40);
	linktable2.addNode(20);

	linktable.merge(&linktable2);
	linktable.logNodes();

	orderlinktable.addNode(2);
	orderlinktable.logNodes();

	//Tree Test Template
	using namespace BinaryTree;
	binaryTreePrefab<> tree;
	tree.root = TreeNode<>();
	tree.addNode(&tree.root, new TreeNode<int>(10));
	cout << tree.count(&tree.root)<<endl;
	


}