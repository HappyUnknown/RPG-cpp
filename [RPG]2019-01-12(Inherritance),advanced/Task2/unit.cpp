#include "Unit.h"
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>

using namespace std;
bool Unit::Evade()
{
	if (rand() % 101 <= evasionChance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Unit::SetHP(int hp)
{
	HP = hp;
}
void Unit::SetDamage(int damage)
{
	this->damage = damage;
}
void Unit::SetEvasion(int evasionChance)
{
	this->evasionChance = evasionChance;
}
void Unit::SetName(string name)
{
	this->unitName = name;
}
int Unit::GetHP()
{
	return HP;
}
int Unit::GetDamage()
{
	return damage;
}
int Unit::GetEvasion()
{
	return evasionChance;
}

std::string Unit::GetName()
{
	return unitName;
}

void Unit::Attack(Unit* obj)
{
	if (obj->Evade() == false)
	{
		obj->SetHP(obj->GetHP() - GetDamage());
		if (obj->GetHP() <= 0)
		{
			obj->HP = 0;
			cout << "Foe " << obj->GetName() << " died.\n";
		}
		else
			cout << "Foe " << obj->GetName() << " taken " << GetDamage() << " damage.\n";
	}
	else
	{
		cout << obj->unitName << " ~EVADED~ " << unitName << "'s attack.\n";
	}
}
void Unit::Show()
{
	cout << typeid(*this).name() + 6;
}
