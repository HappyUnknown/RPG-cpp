#pragma once
class Unit abstract
{
	int HP;
	int damage;
	int evasionChance;
public:
	void SetHP(int hp);
	void SetDamage(int damage);
	void SetEvasion(int evasionChance);
	int GetHP();
	int GetDamage();
	int GetEvasion();
	void Show();
	virtual void Attack(Unit *obj);
	virtual bool Evade();
};