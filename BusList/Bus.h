#pragma once
#include "libs.h"

class Bus
{
private:
	int id;
	string name;
	string surname;
	int number;
public:
	int static num;

	Bus(string name, string surname, int number);

	void GetData();

	int GetId();
};
