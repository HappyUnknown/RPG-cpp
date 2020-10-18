#include "Swordsman.h"
#include <iostream>
using namespace std;

Swordsman::Swordsman()
{
	Unit::SetHP(15);
	Unit::SetDamage(5);
	Unit::SetEvasion(60);
}
Swordsman::Swordsman(int HP, int damage, int evasionChance)
{
	Unit::SetHP(HP);
	Unit::SetDamage(damage);
	Unit::SetEvasion(evasionChance);

}
Swordsman::~Swordsman()
{
	cout << "\nSwordsman Dtor\n";
}
AdvHPSwordsman::AdvHPSwordsman()
{
	AdvHP();
}
AdvAtkSwordsman::AdvAtkSwordsman()
{
	AdvAtk();
}
AdvEvdSwordsman::AdvEvdSwordsman()
{
	AdvEvd();
}
void AdvHPSwordsman::AdvHP()
{
	Swordsman obj;
	int temp = obj.GetHP() + 5;
	Unit::SetHP(temp);
}
AdvHPSwordsman::~AdvHPSwordsman()
{
	cout << "\nSWMAN ~Dtor\n";
}
void AdvAtkSwordsman::AdvAtk()
{
	Swordsman obj;
	int temp = obj.GetDamage() + 5;
	Unit::SetDamage(temp);
}
AdvAtkSwordsman::~AdvAtkSwordsman()
{
	cout << "\nSWMAN ~Dtor\n";
}
void AdvEvdSwordsman::AdvEvd()
{
	Swordsman obj;
	int temp = obj.GetDamage() + 5;
	Unit::SetDamage(temp);
}

AdvEvdSwordsman::~AdvEvdSwordsman()
{
	cout << "\nSWMAN ~Dtor\n";
}
