#pragma once
#include <stdio.h>
#include<iostream>
namespace cpluslinktable
{
	/// <summary>
	/// A classic one direction Node 
	/// </summary>
	/// <typeparam name="DataType">the value type</typeparam>
	template <class DataType=int>
	class Node
	{
	public:
		Node(DataType headdata) :data(headdata), next(nullptr) {}
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
	template <class NodeType=Node<>,class DataType=int>
	class Linktable
	{
	public:
		/// <summary>
		///  Create a linktable with one node
		/// </summary>
		/// <param name="data">node valueֵ</param>
		Linktable(DataType data) :HEAD(new Node<DataType>(data)) {}
		
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
		/// add Node to the end of the linktable
		/// </summary>
		/// <param name="data"></param>
		void addNode(std::initializer_list<DataType> datalist)
		{
			//先看一看最后再哪里
			Node<DataType>* last = this->HEAD;
			while (last->next) {
				last = last->next;
			}
			//把新的元素接到last->next
			for (auto item : datalist)
			{
				Node<DataType>* p = new Node<DataType>(item);
					last->next = p;
					last = p;
			}

		}
		/// <summary>
		/// try to search a node with the value given , if not found ,return -1,if found, return index
		/// </summary>
		/// <param name="param"></param>
		/// <returns></returns>
		int search(DataType param)
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

	protected:
		NodeType* HEAD;
	};

	template <class NodeType = Node<>, class DataType = int>
	class orderLinkTable:public Linktable<NodeType,DataType>
	{
	public:
		orderLinkTable(DataType data):Linktable<NodeType, DataType>(data) {}
		void logNodes()
		{
			std::cout << "The size of the ordered linktable is:" << this->size() << "\n";
			int i = 0;
			for (auto p1 = this->HEAD; p1; p1 = p1->next) {
				printf("link-%p-%p: value[%d] = %d\n", p1, p1->next, i++, p1->data);
			}
		}
	};
	


}