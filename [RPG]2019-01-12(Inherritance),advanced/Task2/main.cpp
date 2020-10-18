#include <iostream>
#include <ctime>
#include <conio.h>
#include "Team.h"
#include "Unit.h"
#include "Game.h"
#include "GameCC.h"
using namespace std;
int main()
{
	srand(time(nullptr));
	char mode;
	cout << "Mods : p - Player vs Computer, c - Computer vs Computer\n";
	mode = _getch();
	GameCC cmpcmp;
	
	if (mode == 'c') 
	{
		GameCC current;
		bool cont;
		current.Show();
		cout << "Press any button to start.\n";
		_getch();
		system("cls");
		int turns = 1;
		while (true)
		{
			cout << "______________\nTurn #" << turns;
			cout << "\n______________\n|Blue team phase|";
			cont = current.TurnBlue();
			current.AddLog();
			if (cont == false)
			{
				break;
			}
			cout << "\n\nPress to continue...\n\n";
			_getch();
			system("cls");
			cout << "______________\nTurn #" << turns;
			cout << "\n______________\n|Red team phase|\n";
			cont = current.TurnRed();
			current.AddLog();
			if (cont == false)
			{
				break;
			}
			cout << "\n\nPress to continue...\n\n";
			_getch();
			system("cls");
			turns++;
		}
		current.ShowAllLog();

	}
	else if (mode=='p')
	{
		GamePC current;
		bool cont;
		current.Show();
		cout << "Press any button to start.\n";
		_getch();
		system("cls");
		int turns = 1;
		while (true)
		{
			cout << "______________\nTurn #" << turns;
			cout << "\n______________\n|Blue team phase|\n";
			cont = current.TurnBlue();
			current.AddLog();
			if (cont == false)
			{
				break;
			}
			cout << "\n\nPress to continue...\n\n";
			_getch();
			system("cls");
			cout << "______________\nTurn #" << turns;
			cout << "\n______________\n|Red team phase|\n";
			cont = current.TurnRed();
			current.AddLog();
			if (cont == false)
			{
				break;
			}
			cout << "\n\nPress to continue...\n\n";
			_getch();
			system("cls");
			turns++;
		}
		current.ShowAllLog();
	}
	else
	{
		cout << "You choosed unacceptable mode\n";
	}
	system("pause");
	return 0;
}