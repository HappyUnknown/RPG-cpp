#pragma once
#include "Team.h"
#include <ctime>
#include <vector>
class GameCC
{
	Team Red;
	Team Blue;
	vector<HPlog>logs;
public:
	bool Continue()
	{

		if (GetBlueTeam().GetUnit(0)->GetHP() <= 0 && GetBlueTeam().GetUnit(1)->GetHP() <= 0 && GetBlueTeam().GetUnit(2)->GetHP() <= 0)
		{
			cout << "\n------RED WON------\n";
			return false;
		}
		else if (GetRedTeam().GetUnit(0)->GetHP() <= 0 && GetRedTeam().GetUnit(1)->GetHP() <= 0 && GetRedTeam().GetUnit(2)->GetHP() <= 0)
		{
			cout << "\n-----BLUE WON------\n";
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
		cout << "\n\nAll battle changes.\n";

		int i = 1;
		for (auto l : logs)
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
	int ChooseFoeRed()
	{
		srand(time(nullptr));
		int foe = rand() % 3;
		while (Red.GetUnit(foe)->GetHP() <= 0)
		{
			foe = rand() % 3;
		}
		return foe;
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
		for (int i = 0; i < 3; i++)
		{
			int foe = ChooseFoeRed();
			if (Blue.GetUnit(i)->GetHP() != 0)
			{
				system("color 1A");

				cout << "\n#" << i + 1 << " Blue " << typeid(*Blue.GetUnit(i)).name() + 6 << " attacked #" << foe + 1 << " Red " << typeid(*Red.GetUnit(foe)).name() + 6 << ".\n";
				int lasthp = Red.GetUnit(foe)->GetHP();
				Blue.GetUnit(i)->Attack(Red.GetUnit(foe));
				cout << "#" << foe + 1 << " Red " << Red.GetUnit(foe)->GetName() << "'s hp has dropped from " << lasthp << " to " << GetRedTeam().GetUnit(foe)->GetHP() << " HP.\n";

				if (Continue() == false)
				{
					cout << "#1 Red : " << GetRedTeam().GetUnit(0)->GetHP() << endl;
					cout << "#2 Red : " << GetRedTeam().GetUnit(1)->GetHP() << endl;
					cout << "#3 Red : " << GetRedTeam().GetUnit(2)->GetHP() << endl;
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
	bool TurnRed()
	{
		for (int i = 0; i < 3; i++)
		{
			int foe = ChooseFoeBlue();
			if (Red.GetUnit(i)->GetHP() != 0)
			{
				system("color 4A");

				cout << "Red " << typeid(*Red.GetUnit(i)).name() + 6 << " attacked #" << foe + 1 << " Blue " << typeid(*Blue.GetUnit(foe)).name() + 6 << ".\n";
				int lasthp = Blue.GetUnit(foe)->GetHP();
				Red.GetUnit(i)->Attack(Blue.GetUnit(foe));
				cout <<"#"<< foe + 1 << " Blue " << Blue.GetUnit(foe)->GetName() << "'s hp has dropped from " << lasthp << " to " << GetBlueTeam().GetUnit(foe)->GetHP() << " HP.\n\n";

				if (Continue() == false)
				{
					cout << "\n#1 Blue : " << GetBlueTeam().GetUnit(0)->GetHP() << endl;
					cout << "#2 Blue : " << GetBlueTeam().GetUnit(1)->GetHP() << endl;
					cout << "#3 Blue : " << GetBlueTeam().GetUnit(2)->GetHP() << endl;
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
		cout << "\n---Red team---\n";
		for (int i = 0; i < 3; i++)
		{
			cout << "#" << i + 1 << " : ";
			Red.GetUnit(i)->Show();
			cout << endl;
		}
		cout << "\n---Blue team---\n";
		for (int i = 0; i < 3; i++)
		{
			cout << "#" << i + 1 << " : ";
			Blue.GetUnit(i)->Show();
			cout << endl;
		}
	}
};
