#pragma once
#include "libs.h"
#include "Bus.h"


class BusList
{
private:
	struct Node
	{
		Bus* bus;
		Node* next;
	};
	Node* phead;
	Node* ptail;

	int size;
public:
	BusList();

	void PushInHead(Bus* a);

	void PushInTail(Bus* a);

	void PushInPos(Bus* a, int pos);

	Bus* PopFromHead();

	Bus* PopFromTail();

	Bus* PopFromPos(int pos);

	Bus* PopForElement(int a);

	void Show();

	void Clear();

	~BusList();
};
