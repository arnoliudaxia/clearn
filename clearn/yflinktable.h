#pragma once
#include <stdio.h>
#include<iostream>
namespace cpluslinktable
{
	template <class DataType>
	class Node
	{
	public:
		Node(DataType headdata)
		{
			this->data = headdata;
			this->next = nullptr;
		}
		DataType data;
		Node* next;

		Node& operator=(const Node innode)
		{
			this->data = innode.data;
			this->next = innode.next;
		}
	};

		
	/// <summary>
	/// this a abstart manager of Nodes, the first node address is stored at HEAD var, the class also exposes some useful API
	/// </summary>
	/// <typeparam name="NodeType">Node or BiNode</typeparam>
	template <class NodeType,class DataType>
	class Linktable
	{
	public:
		/// <summary>
		///  Create a linktable with one node
		/// </summary>
		/// <param name="data">node valueֵ</param>
		Linktable(int data)
		{
			//Node* temp = new Node(data);
			this->HEAD = new Node<DataType>(data);
		}
		
		int size()
		{
			int count=0;
			for (Node<DataType>* p = this->HEAD;p != nullptr;p = p->next)count++;
			return count;
		}
		/// <summary>
		/// print the size of the linktable and each node info
		/// </summary>
		void logNodes()
		{
			std::cout << "The size of the linktable is:" << size()<<"\n";
			int i = 0;
			for (auto p1 = this->HEAD; p1; p1 = p1->next) {
				printf("link-%p-%p: value[%d] = %d\n", p1, p1->next, i++, p1->data);
			}
		}
		/// <summary>
		/// ��������ĩβ����һ���ڵ�
		/// </summary>
		/// <param name="data"></param>
		void addNode(int data)
		{

				// add into the linked-list
				Node<DataType>* p = new Node<DataType>(data);
				// find the last
				Node<DataType>* last = this->HEAD;
					while (last->next) {
						last = last->next;
					}
					// link
					last->next = p;
		}
		/// <summary>
		/// ����������ֵΪparam�Ľڵ㣬����ҵ�����
		/// </summary>
		/// <param name="param"></param>
		/// <returns></returns>
		int search(int param)
		{
			int index = 0;
				bool isFound = false;
				for (Node<DataType>* p = this->HEAD; p; p = p->next) {
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