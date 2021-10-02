#pragma once
//struct Node
//{
//	int data;
//	Node* next;
//};
//struct BiNode
//{
//	Node* last;
//	int data;
//	Node* next;
//};
template <class NodeType,class DataType>
class Linktable
{
public:
	Linktable(DataType data);
	//[[deprecated("Old c with no object view")]]
	//NodeType* initializeNode(int data);

	//void logNodes();
	//void addNode(int data, Node* head);
	//bool search(int param, Node* head);

	NodeType &HEAD;
private:
};

template <class T>
class Node
{
public:
	Node(T headdata);
	T data;
	Node& next;

	Node<T>& operator=(const Node<T> innode)
	{
		this->data = innode.data;
		this->next = innode.next;
	}
};

template<class T>
inline Node<T>::Node(T headdata)
{
	this->data = headdata;
}
