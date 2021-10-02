#pragma once
#include <stdio.h>
namespace mylinktable
{
	class Node
	{
	public:
		Node(int headdata);
		int data;
		Node* next;

		Node& operator=(const Node innode)
		{
			this->data = innode.data;
			this->next = innode.next;
		}
	};


	inline Node::Node(int headdata)
	{
		this->data = headdata;
		this->next = nullptr;
	}


	/// <summary>
	/// 这是一整个链表的抽象模型，里面的节点是另外的类，主要储存链表头的信息并且暴露一些API出来
	/// </summary>
	/// <typeparam name="NodeType">Node or BiNode</typeparam>
	template <class NodeType>
	class Linktable
	{
	public:
		/// <summary>
		///  c++初始化一个单链表对象（自动创建一个Node）,HEAD地址储存在对象的HEAD属性中
		/// </summary>
		/// <param name="data">第一个元素的值</param>
		Linktable(int data)
		{
			//Node* temp = new Node(data);
			this->HEAD = new Node(data);
		}
		//[[deprecated("Old c with no object view")]]
		//NodeType* initializeNode(int data);
		
		/// <summary>
		///  自动打印一个链表内所有元素
		/// </summary>
		void logNodes()
		{
			int i = 0;
			for (auto p1 = this->HEAD; p1; p1 = p1->next) {
				printf("link-%p-%p: value[%d] = %d\n", p1, p1->next, i++, p1->data);
			}
		}
		/// <summary>
		/// 在链表的末尾增加一个节点
		/// </summary>
		/// <param name="data"></param>
		void addNode(int data)
		{

				// add into the linked-list
				Node* p = new Node(data);
				// find the last
				Node* last = this->HEAD;
					while (last->next) {
						last = last->next;
					}
					// link
					last->next = p;
		}
		/// <summary>
		/// 查找链表中值为param的节点，如果找到返回
		/// </summary>
		/// <param name="param"></param>
		/// <returns></returns>
		int search(int param)
		{
			int index = 0;
				bool isFound = false;
				for (Node* p = this->HEAD; p; p = p->next) {
					if (p->data == param) {
						isFound=true;
						break;
					}
					index++;
				}
				return isFound ? index : -1;
		}

	private:
		NodeType* HEAD;
	};


	


}