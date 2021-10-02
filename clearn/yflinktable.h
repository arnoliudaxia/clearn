#pragma once
#include <stdio.h>
namespace cpluslinktable
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
	/// ����һ���������ĳ���ģ�ͣ�����Ľڵ���������࣬��Ҫ��������ͷ����Ϣ���ұ�¶һЩAPI����
	/// </summary>
	/// <typeparam name="NodeType">Node or BiNode</typeparam>
	template <class NodeType>
	class Linktable
	{
	public:
		/// <summary>
		///  c++��ʼ��һ�������������Զ�����һ��Node��,HEAD��ַ�����ڶ����HEAD������
		/// </summary>
		/// <param name="data">��һ��Ԫ�ص�ֵ</param>
		Linktable(int data)
		{
			//Node* temp = new Node(data);
			this->HEAD = new Node(data);
		}
		//[[deprecated("Old c with no object view")]]
		//NodeType* initializeNode(int data);
		
		/// <summary>
		///  �Զ���ӡһ������������Ԫ��
		/// </summary>
		void logNodes()
		{
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
		/// ����������ֵΪparam�Ľڵ㣬����ҵ�����
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