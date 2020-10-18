#pragma once
#include <iostream>
class Unit abstract
{
	int HP;
	int damage;
	int evasionChance;
	std::string unitName;
public:
	void SetHP(int hp);
	void SetDamage(int damage);
	void SetEvasion(int evasionChance);
	void SetName(std::string name);
	int GetHP();
	int GetDamage();
	int GetEvasion();
	std::string GetName();
	void Show();
	virtual void Attack(Unit *obj);
	virtual bool Evade();
};