#pragma once
#include "Unit.h"


class Swordsman : public Unit
{
public:
	Swordsman();
	Swordsman(int HP, int damage, int evasionChance);
	~Swordsman();
};
class AdvHPSwordsman :public Swordsman
{
	AdvHPSwordsman();
	AdvHPSwordsman(int HP, int damage, int evasionChance);
	void AdvHP();
	~AdvHPSwordsman();
};
class AdvAtkSwordsman:public Swordsman
{
	AdvAtkSwordsman();
	AdvAtkSwordsman(int HP, int damage, int evasionChance);
	void AdvAtk();
	~AdvAtkSwordsman();
};
class AdvEvdSwordsman :public Swordsman
{
	AdvEvdSwordsman();
	AdvEvdSwordsman(int HP, int damage, int evasionChance);
	void AdvEvd();
	~AdvEvdSwordsman();
};