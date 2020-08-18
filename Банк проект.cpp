#include <iostream>
#include <fstream>
#include "User2.h"
#include "Terminal2.h"


using namespace std;

const int money = 500;


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

	Bank* one = new Bank();
	cout << "Выберите терминал: \n";
	int terminalnubmer;
	cin >> terminalnubmer;
	Terminal2* terminal = one->GetIdTerminal(terminalnubmer);
	cout << "Введите ид кароточки: \n";
	long id;
	cin >> id;
	terminal->GetUser(id);
	
		int menu;
		do
		{
			cout << "1.Положить наличные на счет\n";
			cout << "2.Снять наличные со счета\n";
			cout << "3.Информация\n";
			cout << "0.Завершить сенас\n";
			cin >> menu;

			switch (menu)
			{
			case 1:
			{
				cout << "Введите сумму для взноса: \n";
				double count;
				cin >> count;
				terminal->Deposite(count);
				terminal->UserWrite();
			}; break;
			case 2:
			{
				cout << "Введите сумму для вычита: \n";
				double count;
				cin >> count;
				terminal->Withdraw(count);
				terminal->UserWrite();
 			}; break;
			case 3:
			{
				terminal->ShowInfo();
			}; break;
			case 0:
			{
				terminal->EjectCard();
			}; break;
			}
		} while (menu != 0);

	system("pause");
	return 0;
}