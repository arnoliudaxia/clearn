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
		///  c++��ʼ��һ������������Զ�����һ��Node��,HEAD��ַ�����ڶ����HEAD������
		/// </summary>
		/// <param name="data">��һ��Ԫ�ص�ֵ</param>
		Linktable(int data)
		{
			//Node* temp = new Node(data);
			this->HEAD = new Node(data);
		}
		//[[deprecated("Old c with no object view")]]
		//NodeType* initializeNode(int data);

		void logNodes()
		{
			int i = 0;
			for (auto p1 = this->HEAD; p1; p1 = p1->next) {
				printf("link-%p-%p: value[%d] = %d\n", p1, p1->next, i++, p1->data);
			}
		}
		void addNode(int data, Node* head)
		{

		}
		//bool search(int param, Node* head);

		NodeType* HEAD;
	private:
	};
	/// <typeparam name="NodeType">Node or BiNode</typeparam>


	


}