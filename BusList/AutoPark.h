#pragma once
#include "libs.h"
#include "BusList.h"
class AutoPark
{
private:
	BusList* In;
	BusList* Out;
public:
	AutoPark();

	void ByeBus();

	void ShowAutoPark();

	void ShowInRoad();

	void DelBus();

	void InRoad();

	void InPark();

	~AutoPark();

};
