#include "libs.h"
#include "BusList.h"

BusList::BusList()
{
	this->phead = nullptr;
	this->ptail = nullptr;
	this->size = 0;
}

void BusList::PushInHead(Bus* a)
{
	size++;
	Node* pnew = new Node();
	pnew->bus = a;
	pnew->next = nullptr;
	if (this->phead == nullptr)
	{
		pnew->next = nullptr;
		this->phead = pnew;
		this->ptail = pnew;
		return;
	}

	pnew->next = this->phead;
	this->phead = pnew;
}

void BusList::PushInTail(Bus* a)
{
	size++;
	Node* pnew = new Node();
	pnew->bus = a;
	pnew->next = nullptr;
	if (this->phead == nullptr)
	{
		pnew->next = nullptr;
		this->phead = pnew;
		this->ptail = pnew;
		return;
	}

	this->ptail->next = pnew;
	this->ptail = pnew;
}

void BusList::PushInPos(Bus* a, int pos)
{
	pos--;
	Node* pnew = new Node();
	pnew->bus = a;
	Node* ptr = this->phead;
	if (pos <= 0)
	{
		size++;
		PushInHead(a);
		return;
	}

	if (pos > this->size)
	{
		size++;
		PushInTail(a);
		return;
	}
	while (pos != 1)
	{
		ptr = ptr->next;
		pos--;
	}


	pnew->next = ptr->next;
	ptr->next = pnew;
	size++;

}

Bus* BusList::PopFromHead()
{
	if (this->phead == nullptr)
	{
		cout << "Array is empty!" << endl;
		return nullptr;
	}
	size--;
	if (this->phead == this->ptail)
	{
		Bus* tem = this->phead->bus;
		delete this->phead;
		this->ptail = nullptr;
		this->phead = nullptr;
		return tem;
	}

	Node* del = this->phead;
	Bus* temp = this->phead->bus;
	this->phead = this->phead->next;

	delete del;
	del = nullptr;
	return temp;
}

Bus* BusList::PopFromTail()
{
	if (this->ptail == nullptr)
	{
		cout << "Array is empty!" << endl;
		return nullptr;
	}
	size--;
	if (this->phead == this->ptail)
	{
		Bus* tem = this->ptail->bus;
		delete this->ptail;
		this->ptail = nullptr;
		this->phead = nullptr;
		return tem;
	}

	Node* del = this->ptail;
	Node* t = this->phead;
	while (t->next != this->ptail)
	{
		t = t->next;
	}
	Bus* temp = del->bus;
	t->next = nullptr;
	this->ptail = t;
	delete del;

	del = nullptr;
	return temp;
}

Bus* BusList::PopFromPos(int pos)
{

	Node* ptr = this->phead;

	if (this->phead == this->ptail)
	{
		this->size--;
		return PopFromHead();
	}

	if (pos <= 0)
	{
		this->size--;
		return PopFromHead();
	}

	if (pos > this->size)
	{
		this->size--;
		return PopFromTail();
	}


	while (pos != 1)
	{
		ptr = ptr->next;
		pos--;
	}

	Node* ptr_ = this->phead;
	while (ptr_ != ptr)
	{
		if (ptr_->next == ptr)
		{
			break;
		}
		ptr_ = ptr_->next;
	}

	ptr_->next = ptr->next;
	Bus* b = ptr->bus;
	delete ptr;
	size--;
	return b;
}

Bus* BusList::PopForElement(int a)
{
	if (a > Bus::num)
	{
		a = Bus::num;
	}
	if (a < 0)
	{
		a = 1;
	}

	Node* ptr = this->phead;
	int k = 0;
	while (ptr != nullptr && ptr->bus->GetId() != a)
	{
		ptr = ptr->next;
		k++;
	}
	k--;

	if (ptr == nullptr)
	{
		cout << "No such Bus!" << endl;
		return nullptr;
	}


	if (ptr == this->phead)
	{
		return this->PopFromHead();
	}
	else if (ptr == this->ptail)
	{
		return this->PopFromTail();
	}

	Node* ptr_ = this->phead;

	while (k != 0)
	{
		ptr_ = ptr_->next;
		k--;
	}

	ptr_->next = ptr->next;

	Bus* btemp = ptr->bus;
	delete ptr;

	return btemp;


}

void BusList::Show()
{
	Node* sh = this->phead;
	while (sh != nullptr)
	{
		sh->bus->GetData();
		sh = sh->next;
	}
}

void BusList::Clear()
{
	if (this->phead != nullptr)
	{
		Node* del = this->phead;
		while (del != nullptr)
		{
			this->phead = this->phead->next;
			delete del->bus;
			delete del;
			del = this->phead;
		}
	}
}

BusList::~BusList()
{
	this->Clear();
}
