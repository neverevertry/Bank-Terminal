#include <iostream>
#include <fstream>
#include "User.h"
#include "Terminal.h"
#include "BanknoteVault.h"


using namespace std;

const int money = 500;


class Bank
{
private:
	Terminal* terminal[4];
public:
	Bank()
	{
		for (int i = 0; i < 4; i++)
			terminal[i] = new Terminal("№" + i);
	}

	Terminal* GetTerminalById(int _TerminalId)
	{
		return terminal[_TerminalId];
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	BanknoteVault** banknote = new BanknoteVault * [5];
	for (int i = 0; i < 5; i++)
		banknote[i] = new BanknoteVault();
	banknote[0]->CurrentNubmers = 999;
	banknote[0]->DenominationBill = 50;
	banknote[1]->CurrentNubmers = 999;
	banknote[1]->DenominationBill = 100;
	banknote[2]->CurrentNubmers = 999;
	banknote[2]->DenominationBill = 500;
	banknote[3]->CurrentNubmers = 999;
	banknote[3]->DenominationBill = 1000;
	banknote[4]->CurrentNubmers = 999;
	banknote[4]->DenominationBill = 5000;

	Bank* one = new Bank();

	while (true)
	{
		cout << "Выберите терминал: \n";
		int IdTerminal;
		cin >> IdTerminal;
		Terminal* terminal = one->GetTerminalById(IdTerminal);
		cout << "Введите ид кароточки: \n";
		long id;
		cin >> id;
		bool CheckUser = terminal->GetUserById(id);


		if (CheckUser)
		{
			int menu;
			do
			{
				cout << "1.Положить наличные на счет\n";
				cout << "2.Снять наличные со счета\n";
				cout << "3.Информация\n";
				cout << "0.Завершить сенас\n";
				if (id == 13)
					cout << "9.Панель настроек\n";
				cin >> menu;

				switch (menu)
				{
				case 1:
				{
					cout << "Введите сумму для взноса: \n";
					double count;
					cin >> count;
					terminal->Deposite(count);
				}; break;
				case 2:
				{
					cout << "Введите сумму для вычита: \n";
					double count;
					cin >> count;
					bool CheckWithdraw = terminal->CheckForIssuingBanknotes(count);
					if (CheckWithdraw)
						terminal->Withdraw(count);
					else
						continue;
				}; break;
				case 3:
				{
					terminal->ShowInfo();
				}; break;
				case 9:
				{
					int AdminMenu;
					do
					{
						cout << "1.Загрузка банкнот\n";
						cout << "2.Проверка на выдачу купюр\n";
						cout << "0.Выход\n";
						cin >> AdminMenu;
						switch (AdminMenu)
						{
						case 1:
						{
							terminal->LoadCash(banknote);
						}; break;
						case 2:
						{
							cout << "Введите сумму для теста\n";
							int count;
							cin >> count;
							terminal->CheckForIssuingBanknotes(count);
						}; break;
						case 55:
						{
							break;
						}; break;
						}
					} while (AdminMenu != 55);

				}; break;
				case 0:
				{
					terminal->EjectCard();
				}; break;
				}
			} while (menu != 0);
		}
		else
		{
			return 0;
		}
	}
	system("pause");
	return 0;
}