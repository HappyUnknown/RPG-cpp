#pragma once
//НЕВОЗМОЖНО СОЗДАТЬ экземпляр базового класса abstracts
#include <iostream>
#include "Unit.h"
#include "Swordsman.h"
#include "Mage.h"
#include "Archer.h"
using namespace std;
class Team
{
private:
	string name;
	Unit **group = new Unit*[3];
public:
	Team()
	{
		this->name = name;
		for (int i = 0; i < 3; i++)
		{
			int number = rand() % 3;
			if (number == 0)
			{
				group[i] = new Swordsman;
			}
			else if (number == 1)
			{
				group[i] = new Mage;
			}
			else if (number == 2)
			{
				group[i] = new Archer;
			}
		}
	}

	void SetName(const string name)
	{
		this->name = name;
	}
	string GetName()
	{
		return name;
	}
	Unit *GetUnit(int num)
	{
		return group[num];
	}
	void DisplayTeam()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << typeid(*group[i]).name() << endl;
			cout << "- HP : " << group[i]->GetHP();
		}
	}
};