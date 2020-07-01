#include "libs.h"
#include "Bus.h"

Bus::Bus(string name, string surname, int number)
{
	this->id = Bus::num++;
	this->name = name;
	this->surname = surname;
	this->number = number;
}

void Bus::GetData()
{
	if (this != nullptr)
	{
		cout << "id - " << this->id << endl;
		cout << "name - " << this->name << endl;
		cout << "surname - " << this->surname << endl;
		cout << "number - " << this->number << endl;
	}
}

int Bus::GetId()
{
	return this->id;
}