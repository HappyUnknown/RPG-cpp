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

		if (GetBlueTeam().GetUnit(0)->GetHP() <= 0 & GetBlueTeam().GetUnit(1)->GetHP() <= 0 && GetBlueTeam().GetUnit(2)->GetHP() <= 0)
		{
			cout << "\n\n------STOP------\n\n";
			return false;
		}
		else if (GetRedTeam().GetUnit(0)->GetHP() <= 0 && GetRedTeam().GetUnit(1)->GetHP() <= 0 && GetRedTeam().GetUnit(2)->GetHP() <= 0)
		{
			cout << "\n\n------STOP------\n\n";

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
		cout << "\n\n\nAll battle changes : \n";

		for (auto l : logs)
		{
			cout << "1-st Blue " << l.firstBlue << " HP" << endl;
			cout << "2-nd Blue " << l.secondBlue << " HP" << endl;
			cout << "3-nd Blue " << l.thirdBlue << " HP" << endl;
			cout << "1-st Red " << l.firstRed << " HP" << endl;
			cout << "2-nd Red " << l.secondRed << " HP" << endl;
			cout << "3-nd Red " << l.thirdRed << " HP" << endl;
			cout << "***NEXT ROUND***\n----------------------------\n\n";
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
				cout << "\nBlue " << typeid(*Blue.GetUnit(i)).name() + 6 << " attacked Red " << typeid(*Red.GetUnit(foe)).name() + 6 << ".\n";
				Blue.GetUnit(i)->Attack(Red.GetUnit(foe));
				cout << "Currently, " << foe << "-st blue has : " << GetRedTeam().GetUnit(foe)->GetHP() << " HP left.\n";
				if (Continue() == false)
				{
					cout << "1-st red : " << GetRedTeam().GetUnit(0)->GetHP() << endl;
					cout << "2-st red : " << GetRedTeam().GetUnit(1)->GetHP() << endl;
					cout << "3-st red : " << GetRedTeam().GetUnit(2)->GetHP() << endl;
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
				cout << "\nRed " << typeid(*Red.GetUnit(i)).name() + 6 << " attacked Blue " << typeid(*Blue.GetUnit(foe)).name() + 6 << ".\n";
				Red.GetUnit(i)->Attack(Blue.GetUnit(foe));
				cout << "Currently, " << foe << "-st red has : " << GetBlueTeam().GetUnit(foe)->GetHP() << " HP left.\n";
				if (Continue() == false)
				{
					cout << "\n1-st blue : " << GetBlueTeam().GetUnit(0)->GetHP() << endl;
					cout << "2-st blue : " << GetBlueTeam().GetUnit(1)->GetHP() << endl;
					cout << "3-st blue : " << GetBlueTeam().GetUnit(2)->GetHP() << endl;
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
			cout << i + 1 << "-st : ";
			Red.GetUnit(i)->Show();
			cout << endl;
		}
		cout << "\n---Blue team---\n";
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "-st : ";
			Blue.GetUnit(i)->Show();
			cout << endl;
		}
	}
};
