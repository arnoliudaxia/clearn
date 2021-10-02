#pragma once
class Linktable
{
public:
	struct Node
	{
		int data;
		Node* next;
	};

	Node* initializeNode(int data);

	void logNodes(Node* start);
	void addNode(int data, Node* head);
	bool search(int param, Node* head);
};

