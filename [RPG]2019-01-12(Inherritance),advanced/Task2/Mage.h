#pragma once
#include "Unit.h"

class Mage :public Unit
{
public:
	Mage();
	Mage(int HP, int damage, int evasionChance);
	~Mage();
};
class AdvHPMage :public Mage
{
	AdvHPMage();
	AdvHPMage(int HP, int damage, int evasionChance);
	void AdvHP();
	~AdvHPMage();
};
class AdvAtkMage :public Mage
{
	AdvAtkMage();
	AdvAtkMage(int HP, int damage, int evasionChance);
	void AdvAtk();
	~AdvAtkMage();
};
class AdvEvdMage :public Mage
{
	AdvEvdMage();
	AdvEvdMage(int HP, int damage, int evasionChance);
	void AdvEvd();
	~AdvEvdMage();
};
