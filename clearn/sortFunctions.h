#pragma once

enum sortType
{
	smallTobig,
	bigTosmall,
};
int* bubbleSortLazy(int input[], size_t length, sortType sorttype);