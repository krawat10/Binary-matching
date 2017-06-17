#include "Header.h"
#include <cstdlib>

queue::queue()
{
	this->head = 0;
	this->tail = 0;
	this->memorySize = 5;
	values = (int*)malloc(sizeof(int)*5);
}

void queue::refresh()
{
	this->head = 0;
	this->tail = 0;
}

queue::~queue()
{
	free(values);
}

void queue::pop()
{
	head++;
	if ((3 * size() < memorySize) && (size() > 5))
	{
		resize_memory(memorySize / 2);
	}
}

bool queue::empty()
{
	return ((tail - head) == 0);
}



void queue::pseudoClean()
{
	free(values);
	this->head = 0;
	this->tail = 0;
	this->memorySize = 5;
	values = (int*)malloc(sizeof(int) * 5);
}

void queue::resize_memory(int n_sz)
{
	memorySize = n_sz;
	int* buffer = (int*)malloc(sizeof(int)*n_sz);
	for (int i = head, j = 0; i < tail; i++, j++)
	{
		buffer[j] = values[i];
	}
	tail = size();
	head = 0;
	free(values);
	values = buffer;
}

int &queue::front()
{
	return values[head];
}

int queue::size()
{
	return tail - head;
}

void queue::push(int value)
{
	values[tail] = value;
	tail++;
	if (tail >= memorySize)
	{
			resize_memory(memorySize*2 + 10);
	}

}