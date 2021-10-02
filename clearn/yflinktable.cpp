#include "yflinktable.h"
#include <malloc.h>
#include<stdio.h>
#include <iostream>

Linktable::Linktable(int data)
{
	this->HEAD = initializeNode(data);
}

/// <summary>
/// 初始化一个单链表对象（自动创建一个Node）
/// </summary>
/// <param name="data">头Node数据</param>
/// <returns>返回头Node地址（head）</returns>
Linktable::Node* Linktable::initializeNode(int data)
{
	Linktable::Node* p = (Linktable::Node*)malloc(sizeof(Linktable::Node));
	p->data = data;
	p->next = nullptr;
	return p;
}
/// <summary>
/// 自动打印一个链表的长度及其内所有元素
/// </summary>
/// <param name="head"></param>
void Linktable::logNodes()
{
	// print the link-list
	
	std::cout << "The size of this LinkTable is " << size()<<"\n";
	for (Node* p1 = this->HEAD; p1; p1 = p1->next) {
		static int i = 0;
		printf("link-%p-%p: value[%d] = %d\n", p1, p1->next, i++, p1->data);
	}
}

void Linktable::addNode(int data)
{
	// add into the linked-list
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	// find the last
	Node* last = this->HEAD;
		while (last->next) {
			last = last->next;
		}
		// link
		last->next = p;
}
bool Linktable::search(int param)
{
	bool isFound = false;
	for (Node* p = this->HEAD; p; p = p->next) {
		if (p->data == param) {
			isFound = true;
			break;
		}
	}
	return isFound;
}

int Linktable::size()
{
	int size = 0;
	for (Node* p = this->HEAD; p != nullptr; p = p->next) size++;
	return size;
}

