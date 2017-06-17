#include "Header.h"
#include <cstdlib>

stack::stack()
{
	this->currentPosition = 0;
	this->memorySize = 5;
	values = (int*)malloc(sizeof(int) *5);
}

stack::~stack()
{
	free(values);
}

void stack::pop()
{
	currentPosition--;
	if ((3 * currentPosition < memorySize) && (currentPosition > 1))
	{
		resize_memory(memorySize / 2);
	}
}

void stack::setSize(int size)
{
	currentPosition = 0;
}

bool stack::empty()
{
	return (currentPosition == 0);
}

void stack::pseudoClean()
{
	this->currentPosition = 0;;
}

void stack::resize_memory(int n_sz)
{
	memorySize = n_sz;
	int* buffer = (int*)malloc(sizeof(int)*n_sz);
	for (int i = 0, j = 0; i < currentPosition; i++, j++)
	{
		buffer[j] = values[i];
	}
	free(values);
	values = buffer;
}

int stack::top()
{
	return values[currentPosition - 1];
}

int stack::size()
{
	return currentPosition;
}

void stack::push(int value)
{
	values[currentPosition] = value;
	currentPosition++;
	if (currentPosition == memorySize)
	{
		resize_memory(memorySize * 2 + 10);
	}
}

int &stack::at(int index)
{
	return values[index];
}