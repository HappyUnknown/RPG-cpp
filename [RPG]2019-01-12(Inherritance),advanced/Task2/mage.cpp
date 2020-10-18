#include "Mage.h"
#include <iostream>
using namespace std;
Mage::Mage()
{
	Unit::SetHP(8);
	Unit::SetDamage(10);
	Unit::SetEvasion(30);
}
Mage::Mage(int maxHP, int damage, int evasionChance)
{
	Unit::SetHP(maxHP);
	Unit::SetDamage(damage);
	Unit::SetEvasion(evasionChance);
}
AdvHPMage::AdvHPMage()
{
	AdvHP();
}
AdvAtkMage::AdvAtkMage()
{
	AdvAtk();
}
AdvEvdMage::AdvEvdMage()
{
	AdvEvd();
}
void AdvHPMage::AdvHP()
{
	Mage obj;
	int temp = obj.GetHP() + 5;
	Unit::SetHP(temp);
}
AdvHPMage::~AdvHPMage()
{
	cout << "\nMage ~Dtor\n";
}
void AdvAtkMage::AdvAtk()
{
	Mage obj;
	int temp = obj.GetDamage() + 5;
	Unit::SetDamage(temp);
}
AdvAtkMage::~AdvAtkMage()
{
	cout << "\nMage ~Dtor\n";
}
void AdvEvdMage::AdvEvd()
{
	Mage obj;
	int temp = obj.GetDamage() + 5;
	Unit::SetDamage(temp);
}

AdvEvdMage::~AdvEvdMage()
{

	cout << "\nMage ~Dtor\n";
}

Mage::~Mage()
{
	cout << "\nMage Dtor\n";
}
