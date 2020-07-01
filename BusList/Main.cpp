#include "libs.h"
#include "Bus.h"
#include "BusList.h"
#include "AutoPark.h"

int Bus::num = 1;

void main() 
{

	setlocale(LC_CTYPE, "ukr");
	
	
	AutoPark* ap = new AutoPark();

	int counter = 1;
	int ch = 1;
	while (true)
	{
	  do
	  {
		system("cls");
		if (counter == 1) SetCol(12);
		cout << "Купити автобус" << endl;
		SetCol(7);
		if (counter == 2) SetCol(12);
		cout << "Продати автобус" << endl;
		SetCol(7);
		if (counter == 3) SetCol(12);
		cout << "Вiдправити автобус в дорогу" << endl;
		SetCol(7);
		if (counter == 4) SetCol(12);
		cout << "Вiдправити автобус в автопарк" << endl;
		SetCol(7);
		if (counter == 5) SetCol(12);
		cout << "Показати автобуси в дорозi" << endl;
		SetCol(7);
		if (counter == 6) SetCol(12);
		cout << "Показати автобуси в автопарку" << endl;
		SetCol(7);

		ch = _getch();
		switch (ch)
		{
		case 224:
		{
			switch (_getch())
			{
			case 72: counter > 1 ? counter-- : counter = 6; break;
			case 80: counter < 6 ? counter++ : counter = 1; break;
			}
			break;
		}
		}
	  }while (ch != 13);
	  switch (counter) 
	  {
	  case 1: 
	  {
		  ap->ByeBus();
		  break; 
	  }
	  case 2: 
	  {
		  ap->DelBus();
		  break; 
	  }
	  case 3: 
	  {
		  ap->InRoad();
		  Stop();
		  break; 
	  }
	  case 4: 
	  {
		  ap->InPark();
		  Stop();
		  break; 
	  }
	  case 5: 
	  {
		  ap->ShowInRoad();
		  Stop();
		  break; 
	  }
	  case 6: 
	  {
		  ap->ShowAutoPark();
		  Stop();
		  break; 
	  }
	  }
	}

	delete ap;

	

	
}