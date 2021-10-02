#pragma once
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

		//void logNodes();
		//void addNode(int data, Node* head);
		//bool search(int param, Node* head);

		NodeType* HEAD;
	private:
	};
	/// <typeparam name="NodeType">Node or BiNode</typeparam>


	


}