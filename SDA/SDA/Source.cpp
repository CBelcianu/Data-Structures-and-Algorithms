#include "SortedSet.h"
#include "Tests.h"
#include<crtdbg.h>
#include<string.h>

using namespace std;
/*
void printMenu()
{
	cout << "1. list all the players\n";
	cout << "2. list all the players having less than 180 days on their contract\n";
	cout << "3. add a new player\n";
	cout << "4. simulate a mounth\n";
	cout << "0. exit\n";
}
*/

int main()
{
	Tests::testAll();
	
	SortedSet ss;
	Contract c1{ 90,"Player 1" };
	Contract c2{ 30,"Player 2" };
	Contract c3{ 40,"Player 3" };
	Contract c4{ 20,"Player 4" };
	Contract c5{ 150,"Player 5" };
	Contract c6{ 190,"Player 6" };
	Contract c7{ 110,"Player 7" };
	ss.insertSS(c1);
	ss.insertSS(c2);
	ss.insertSS(c3);
	ss.insertSS(c4);
	ss.insertSS(c5);
	ss.insertSS(c6);
	ss.insertSS(c7);
	int keepAlive = 1;
	while (keepAlive)
	{
		printMenu();
		int comm{ 0 };
		cout << "Enter command: ";
		cin >> comm;
		cin.ignore();
		if (comm == 0)
			keepAlive = 0;
		if (comm == 1)
		{
			Iterator* j = ss.iter();
			if (ss.getSize()==0)
				cout << "No players left\n";
			else	
			for (int i = 0; i < ss.getSize(); i++)
			{
				node* c = j->next();
				cout << c->data.getDays() << " " << c->data.getPlayer() << endl;
			}
		}
		if (comm == 2)
		{
			Iterator* j = ss.iter();
			for (int i = 0; i < ss.getSize(); i++)
			{
				node* c = j->next();
				if (c->data.getDays() <= 180)
					cout << c->data.getDays() << " " << c->data.getPlayer() << endl;
			}
		}
		if (comm == 3)
		{
			int d;
			string n;
			cout << "days: ";
			cin >> d;
			cin.ignore();
			cout << "name: ";
			getline(cin, n);
			Contract cc{ d,n };
			ss.insertSS(cc);
		}
		if (comm == 4)
		{
			int s = 30;
			Iterator* j = ss.iter();
			for (int i = 0; i < ss.getSize(); i++)
			{
				node* c = j->next();
				c->data.sim(s);
			}
			for (int i = 0; i < ss.getSize(); i++)
			{
				node* c = j->next();
				if (c->data.getDays() <= 0) {
					ss.removeSS(c->data);
					j = ss.iter();
				}
			}
		}
	}
	
	return 0;
}