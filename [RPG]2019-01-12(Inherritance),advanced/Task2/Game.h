#pragma once
#include "Team.h"
#include <ctime>
#include <vector>
struct HPlog
{
	int firstRed;
	int secondRed;
	int thirdRed;
	int firstBlue;
	int secondBlue;
	int thirdBlue;
};

class GamePC
{
	Team Red;
	Team Blue;
	vector<HPlog>logs;

public:
	bool Continue()
	{

		if (GetBlueTeam().GetUnit(0)->GetHP() <= 0 && GetBlueTeam().GetUnit(1)->GetHP() <= 0 && GetBlueTeam().GetUnit(2)->GetHP() <= 0)
		{
			cout << "\n\n------RED WON------\n\n";
			return false;
		}
		else if (GetRedTeam().GetUnit(0)->GetHP() <= 0 && GetRedTeam().GetUnit(1)->GetHP() <= 0 && GetRedTeam().GetUnit(2)->GetHP() <= 0)
		{
			cout << "\n\n-----BLUE WON------\n\n";
			return false;
		}
		else
		{
			return true;
		}
	}
	void AddLog()
	{
		HPlog allhp;
		allhp.firstRed = GetRedTeam().GetUnit(0)->GetHP();
		allhp.secondRed = GetRedTeam().GetUnit(1)->GetHP();
		allhp.thirdRed = GetRedTeam().GetUnit(2)->GetHP();
		allhp.firstBlue = GetBlueTeam().GetUnit(0)->GetHP();
		allhp.secondBlue = GetBlueTeam().GetUnit(1)->GetHP();
		allhp.thirdBlue = GetBlueTeam().GetUnit(2)->GetHP();
		logs.push_back(allhp);
	}
	void ShowAllLog()const
	{
		cout << "\n\n\nAll battle changes.\n";
		int i = 1;
		for (const auto& l : logs)
		{
			cout << "\n***#" << i << " ROUND***\n----------------------------\n\n";
			cout << "#1 Blue " << l.firstBlue << " HP" << endl;
			cout << "#2 Blue " << l.secondBlue << " HP" << endl;
			cout << "#3 Blue " << l.thirdBlue << " HP" << endl;
			cout << "#1 Red " << l.firstRed << " HP" << endl;
			cout << "#2 Red " << l.secondRed << " HP" << endl;
			cout << "#3 Red " << l.thirdRed << " HP" << endl;
			i++;
		}
	}

	Team GetRedTeam()
	{
		return Red;
	}
	Team GetBlueTeam()
	{
		return Blue;
	}
	int ChooseFoeBlue()
	{
		srand(time(nullptr));
		int foe = rand() % 3;
		while (Blue.GetUnit(foe)->GetHP() <= 0)
		{
			foe = rand() % 3;
		}
		return foe;
	}
	bool TurnBlue()
	{
		system("color 1A");
		cout << "\n---Your team---\n";
		for (int i = 0; i < 3; i++)
		{
			cout << "#" << i + 1 << " mate : " << typeid(*Blue.GetUnit(i)).name() + 5;
			if (Blue.GetUnit(i)->GetHP() <= 0) { cout << ": Dead\n"; }
			else  cout << " [HP:" << Blue.GetUnit(i)->GetHP() << " ATK:" << Blue.GetUnit(i)->GetDamage() << " EVASION:" << Blue.GetUnit(i)->GetEvasion() << "]\n";
		}
		cout << "\n----Red team----\n";
		for (int i = 0; i < 3; i++)
		{
			cout << "#" << i + 1 << " enemy : " << typeid(*Red.GetUnit(i)).name() + 5;
			if (Red.GetUnit(i)->GetHP() <= 0)cout << ": Dead\n";
			else cout << " [HP:" << Red.GetUnit(i)->GetHP() << " ATK:" << Red.GetUnit(i)->GetDamage() << " EVASION:" << Red.GetUnit(i)->GetEvasion() << "]\n";
		}
		for (int i = 0; i < 3; i++)
		{
			if (Blue.GetUnit(i)->GetHP() == 0)
				continue;
			else
			{
				int foe;
				cout << "\nChoose foe for" << typeid(*Blue.GetUnit(i)).name() + 5 << " (1-3): ";
				cin >> foe;
				if (foe < 0 || foe > 2)
				{
					do
					{
						cout << "Only 3 members\n";
						cout << "Choose foe for" << typeid(*Blue.GetUnit(i)).name() + 5 << " (1-3): ";
						cin >> foe;
					} while (foe < 0 || foe > 2);
				}
				if(Red.GetUnit(foe)->GetHP() <= 0)
				do
				{
					cout << "\nYou shouldn't kill dead foes\n";
					cout << "Choose foe for" << typeid(*Blue.GetUnit(i)).name() + 5 << " (1-3): ";
					cin >> foe;
				} while (Red.GetUnit(foe)->GetHP() <= 0);

				foe--;
				if (Blue.GetUnit(i)->GetHP() != 0)
				{
					cout << "\n#" << i + 1 << " Blue " << typeid(*Blue.GetUnit(i)).name() + 6 << " attacked #" << foe + 1 << " Red " << typeid(*Red.GetUnit(foe)).name() + 6 << ".\n";
					int lasthp = Red.GetUnit(foe)->GetHP();
					Blue.GetUnit(i)->Attack(Red.GetUnit(foe));
					cout << "#" << foe + 1 << " Red " << GetRedTeam().GetUnit(foe)->GetName() << "'s hp has dropped from " << lasthp << " to " << GetRedTeam().GetUnit(foe)->GetHP() << endl;
					if (Continue() == false)
					{
						cout << "#1 red : " << GetRedTeam().GetUnit(0)->GetHP() << endl;
						cout << "#2 red : " << GetRedTeam().GetUnit(1)->GetHP() << endl;
						cout << "#3 red : " << GetRedTeam().GetUnit(2)->GetHP() << endl;
						return false;
					}
					else
					{
						continue;
					}
				}
				else
				{
					continue;
				}
			}
			return true;
		}
	}
	bool TurnRed()
	{
		system("color 4A");
		for (int i = 0; i < 3; i++)
		{
			cout << "#" << i + 1 << " mate : ";
			if (Blue.GetUnit(i)->GetHP() == 0)
				cout << "Dead";
			else
				cout << Blue.GetUnit(i)->GetHP() << " HP";
			cout << endl;
		}
		for (int i = 0; i < 3; i++)
		{
			cout << "#" << i + 1 << " enemy : ";
			if (Red.GetUnit(i)->GetHP() == 0)
				cout << "Dead";
			else
				cout << Red.GetUnit(i)->GetHP() << " HP";
			cout << endl;
		}
		cout << "--------------\n";
		for (int i = 0; i < 3; i++)
		{

			int foe = ChooseFoeBlue();
			if (Red.GetUnit(i)->GetHP() != 0)
			{

				cout << "\n#" << i + 1 << " Red " << typeid(*Red.GetUnit(i)).name() + 6 << " attacked #" << foe + 1 << " blue " << typeid(*Red.GetUnit(foe)).name() + 6 << ".\n";
				int lasthp = Red.GetUnit(foe)->GetHP();
				Red.GetUnit(i)->Attack(Blue.GetUnit(foe));
				cout << "#" << foe + 1 << " Blue " << GetBlueTeam().GetUnit(foe)->GetName() << "'s hp has dropped from " << lasthp << " to " << GetBlueTeam().GetUnit(foe)->GetHP() << endl;
				if (Continue() == false)
				{
					cout << "#1 blue : " << GetBlueTeam().GetUnit(0)->GetHP() << endl;
					cout << "#2 blue : " << GetBlueTeam().GetUnit(1)->GetHP() << endl;
					cout << "#3 blue : " << GetBlueTeam().GetUnit(2)->GetHP() << endl;
					return false;

				}
				else
				{
					continue;
				}

			}
			else
			{
				continue;
			}
		}
		return true;
	}
	void Show()
	{
		cout << "---Red team---\n";
		for (int i = 0; i < 3; i++)
		{
			cout << "#" << i + 1 << " : ";
			Red.GetUnit(i)->Show();
			cout << endl;
		}
		cout << "---Blue team---\n";
		for (int i = 0; i < 3; i++)
		{
			cout << "#" << i + 1 << " : ";
			Blue.GetUnit(i)->Show();
			cout << endl;
		}

	}
};