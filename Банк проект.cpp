#include <iostream>
#include <fstream>
#include "User2.h"
#include "Terminal2.h"


using namespace std;

class Bank
{
private:
	Terminal2* terminal[4];
public:
	Bank()
	{
		for (int i = 0; i < 4; i++)
			terminal[i] = new Terminal2("№" + i);
	}

	Terminal2* GetIdTerminal(int _TerminalId)
	{
		return terminal[_TerminalId];
	}
};



int main()
{
	setlocale(LC_ALL, "Russian");
	const int money = 500;
	long id;

	Bank* one = new Bank();
	Terminal2* terminal = one->GetIdTerminal(3);
	User2* user = terminal->CheckUser(terminal, money);
	/*one->terminal[1]->CheckUser(one->terminal[1], money);
	User2* user = one->terminal[1]->CheckUser(one->terminal[1], money);*/
	
		int menu;
		do
		{
			cout << "1.Положить наличные на счет\n";
			cout << "2.Снять наличные со счета\n";
			cout << "3.Информация\n";
			cout << "0.Выход\n";
			cin >> menu;

			switch (menu)
			{
			case 1:
			{
				user->Deposite(100);
				terminal->WriteUser(user);
			}; break;
			case 2:
			{
				user->Withdraw(50);
				terminal->WriteUser(user);
			}; break;
			case 3:
			{
				user->ShowInfo();
			}; break;
			case 0:
			{
				break;
			}; break;
			}
		} while (menu != 0);

	system("pause");
	return 0;
}