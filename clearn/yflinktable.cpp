
#include "yflinktable.h"
#include <malloc.h>
#include <stdio.h>

Linktable::Node* Linktable::initializeNode(int data)
{
	Linktable::Node* p = (Linktable::Node*)malloc(sizeof(Linktable::Node));
	p->data = data;
	p->next = nullptr;
	return p;
}
void Linktable::logNodes(Node* head)
{
	// print the link-list
	Node* p1 = NULL;
	int i = 0;
	for (p1 = head; p1; p1 = p1->next) {
		printf("link-%p-%p: value[%d] = %d...\n", p1, p1->next, i++, p1->data);
	}
}

void Linktable::addNode(int data,Node* head)
{
	// add into the linked-list
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	// find the last
	Node* last = head;
		while (last->next) {
			last = last->next;
		}
		// link
		last->next = p;
}

