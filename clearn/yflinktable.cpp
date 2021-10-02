#include "yflinktable.h"
#include <malloc.h>
#include<stdio.h>
#include <iostream>



int Linktable::size()
{
	int size = 0;
	for (Node* p = this->HEAD; p != nullptr; p = p->next) size++;
	return size;
}

