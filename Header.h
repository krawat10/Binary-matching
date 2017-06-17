#pragma once

class queue
{
public:
	queue();
	void refresh();
	~queue();
	void push(int value);
	int &front();
	int size();
	void pop();
	bool empty();
	void pseudoClean();
protected:
	void resize_memory(int n_sz);
	int currentPosition;
	int memorySize;
	int head;
	int tail;
	int* values;
};

class stack
{
public:
	stack();
	~stack();
	void push(int value);
	int & at(int index);
	int top();
	int size();
	void pop();
	void setSize(int size);
	bool empty();
	void pseudoClean();
protected:
	void resize_memory(int n_sz);
	int currentPosition;
	int memorySize;
	int* values;
};