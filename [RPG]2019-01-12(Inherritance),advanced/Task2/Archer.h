#pragma once
#include "Unit.h"

class Archer : public Unit
{

public:
	Archer();
	Archer(int HP, int damage, int evasionChance);
	void OldAttack(Unit *obj);
	//---------------------\/
	bool TrueArrow();
	void Attack(Unit *obj);
	//---------------------
	~Archer();
};
class AdvHPArcher :public Archer
{
	AdvHPArcher();
	AdvHPArcher(int HP, int damage, int evasionChance);
	void AdvHP();
	~AdvHPArcher();
};
class AdvAtkArcher :public Archer
{
	AdvAtkArcher();
	AdvAtkArcher(int HP, int damage, int evasionChance);
	void AdvAtk();
	~AdvAtkArcher();
};
class AdvEvdArcher :public Archer
{
	AdvEvdArcher();
	AdvEvdArcher(int HP, int damage, int evasionChance);
	void AdvEvd();
	~AdvEvdArcher();
};