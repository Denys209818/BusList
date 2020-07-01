#include "libs.h"

void test()
{
	cout << "OK" << endl;
	_getch();
}

void Stop()
{
	_getch();
	system("cls");
}

void SetCol(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}