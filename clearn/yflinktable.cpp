#include "yflinktable.h"
#include <malloc.h>
#include<stdio.h>

/// <summary>
/// c++初始化一个单链表对象（自动创建一个Node）,HEAD地址储存在对象的HEAD属性中
/// </summary>
/// <typeparam name="NodeType">Node or BiNode</typeparam>
/// <param name="data">第一个元素的值</param>
template <class NodeType, class DataType>
Linktable<NodeType, DataType>::Linktable(DataType data)
{
	auto x=*new Node<DataType>(10);
	//Node<DataType> headnode(data);
	this->HEAD = x;
}


///// <summary>
///// (纯c)初始化一个单链表对象（自动创建一个Node）
///// </summary>
///// <param name="data">头Node数据</param>
///// <returns>返回头Node地址（head）</returns>
//template <class NodeType, class DataType>
//NodeType* Linktable<NodeType, DataType>::initializeNode(int data)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = data;
//	p->next = nullptr;
//	return p;
//}
//template<class NodeType, class DataType>
//void Linktable<NodeType, DataType>::logNodes()
//{
//		int i = 0;
//	for (auto p1 = this->HEAD; p1; p1 = p1->next) {
//		printf("link-%p-%p: value[%d] = %d...\n", p1, p1->next, i++, p1->data);
//	}
//}
///// <summary>
///// 自动打印一个链表内所有元素
///// </summary>
///// <param name="head"></param>
//void Linktable::logNodes(Node* head)
//{
//	// print the link-list
//	Node* p1 = NULL;
//	int i = 0;
//	for (p1 = head; p1; p1 = p1->next) {
//		printf("link-%p-%p: value[%d] = %d...\n", p1, p1->next, i++, p1->data);
//	}
//}
//
//void Linktable::addNode(int data,Node* head)
//{
//	// add into the linked-list
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = data;
//	p->next = NULL;
//	// find the last
//	Node* last = head;
//		while (last->next) {
//			last = last->next;
//		}
//		// link
//		last->next = p;
//}
//bool Linktable::search(int param, Node* head)
//{
//	Node* p=head;
//	bool isFound = false;
//	for (p = head; p; p = p->next) {
//		if (p->data == param) {
//			isFound = true;
//			break;
//		}
//	}
//	return isFound;
//}

