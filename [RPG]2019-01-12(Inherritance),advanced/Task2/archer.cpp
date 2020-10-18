#include "Archer.h"

#include <iostream>
using namespace std;
Archer::Archer()
{
	Unit::SetHP(12);
	Unit::SetDamage(4);
	Unit::SetEvasion(40);
}
Archer::Archer(int maxHP, int damage, int evasionChance)
{
	Archer::SetHP(maxHP);
	Archer::SetDamage(damage);
	Archer::SetEvasion(evasionChance);
}
bool Archer::TrueArrow()
{
	if (rand() % 100 < 30)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Archer::Attack(Unit *obj)
{
	if (TrueArrow() == true)
	{
		cout << "TRUE ARROW - Miss chance = 0%\n";
		cout << "Before combat : " << obj->GetHP() << endl;
		obj->SetHP(obj->GetHP() - GetDamage());
		if (obj->GetHP() < 0)
		{
			obj->SetHP(0);
			cout << "Unit died.\n";
		}

	}
	else
	{
		if (obj->Evade() == false)
		{
			obj->SetHP(obj->GetHP() - GetDamage());
			if (obj->GetHP() < 0)
			{
				obj->SetHP(0);
				cout << "Unit died.\n";
			}
		}
	}
}
void Archer::OldAttack(Unit *obj)
{

	if (obj->Evade() == false)
	{
		obj->SetHP(obj->GetHP() - GetDamage());
		if (obj->GetHP() < 0)
		{
			obj->SetHP(0);
			cout << "Unit died.\n";
		}
	}
}
Archer::~Archer()
{
	cout << "\nArcher Dtor\n";
}
AdvHPArcher::AdvHPArcher()
{
	AdvHP();
}
AdvAtkArcher::AdvAtkArcher()
{
	AdvAtk();
}
AdvEvdArcher::AdvEvdArcher()
{
	AdvEvd();
}
void AdvHPArcher::AdvHP()
{
	Archer obj;
	int temp = obj.GetHP() + 5;
	Unit::SetHP(temp);
}
AdvHPArcher::~AdvHPArcher()
{
	cout << "\nARCHER ~Dtor\n";
}
void AdvAtkArcher::AdvAtk()
{
	Archer obj;
	int temp = obj.GetDamage() + 5;
	Unit::SetDamage(temp);
}

AdvAtkArcher::~AdvAtkArcher()
{
	cout << "\nARCHER ~Dtor\n";
}
void AdvEvdArcher::AdvEvd()
{
	Archer obj;
	int temp = obj.GetDamage() + 5;
	Unit::SetDamage(temp);
}
AdvEvdArcher::~AdvEvdArcher()
{

	cout << "\nARCHER ~Dtor\n";
}
