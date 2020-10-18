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

void Unit::Attack(Unit *obj)
{
	if (obj->Evade() == false)
	{
		obj->HP = obj->HP - damage;
		if (obj->HP < 0)
		{
			obj->HP = 0;
			cout << "Foe died.\n";
		}
	}
	else
	{
		cout << "/-/-/-EVADE-/-/-/\n";
	}
}
void Unit::Show()
{
	cout << typeid(*this).name() + 6;
}
