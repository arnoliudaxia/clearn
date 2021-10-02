#pragma once
class Linktable
{
public:
	struct Node
	{
		int data;
		Node* next;
	};

	Linktable(int data);


	void logNodes(Node* head);
	void addNode(int data);
	bool search(int param);
	int size();

	Node* HEAD;
private:
	Node* initializeNode(int data);
};

