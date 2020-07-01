#include "libs.h"
#include "AutoPark.h"

AutoPark::AutoPark()
{
	this->In = new BusList();
	this->Out = new BusList();
}

void AutoPark::ByeBus()
{
	string name;
	string surname;
	int number;
	cout << "Enter name busman - ";
	cin >> name;
	cout << "Enter surname busman - ";
	cin >> surname;
	cout << "Enter numer road - ";
	cin >> number;
	In->PushInTail(new Bus(name, surname, number));
}

void AutoPark::ShowAutoPark()
{
	this->In->Show();
}

void AutoPark::ShowInRoad()
{
	this->Out->Show();
}

void AutoPark::DelBus()
{
	this->In->Show();
	this->Out->Show();
	int id;
	cout << "Enter id - ";
	cin >> id;

	if (this->In->PopForElement(id) == nullptr)
	{
		cout << "In Autopark | " << endl;
		this->Out->PopForElement(id);
		cout << "In Road | " << endl;
		_getch();
	}
}

void AutoPark::InRoad()
{
	int a;
	this->In->Show();
	cout << "Enter id - ";
	cin >> a;
	Bus* temp = this->In->PopForElement(a);
	if (temp != nullptr)
	{
		this->Out->PushInTail(temp);
	}
}

void AutoPark::InPark()
{
	int a;
	this->Out->Show();
	cout << "Enter id - ";
	cin >> a;
	Bus* temp = this->Out->PopForElement(a);
	if (temp != nullptr)
	{
		this->In->PushInTail(temp);
	}
}

AutoPark::~AutoPark()
{
	delete this->In;
	delete this->Out;
}
