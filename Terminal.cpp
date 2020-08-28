#define _CRT_SECURE_NO_WARNINGS
#include "Terminal.h"
#include <iostream>
#include "User.h"
#include "BanknoteVault.h"

using namespace std;

Terminal:: Terminal(string _NameTerminal)
{
	NameTerminal = _NameTerminal;
	user = NULL;
	usersearch = new UserBase();
	CashKeeper = NULL;
}

bool Terminal::GetUserById(long _id)
{
	
	this->user = usersearch->GetUserById(_id);

	int count = 0;
	bool CheckUser = false;
	
	while (!CheckUser)
	{
		if (this->user == NULL)
		{
			int id;
			cout << "Неверный ИД, повторите попытку\n";
			cin >> id;
			this->user = usersearch->GetUserById(id);
			count++;
			CheckUser = false;
		}
		else
		{
			cout << "Авторизация прошла успешно!\n";
			CheckUser = true;
			return CheckUser;
		}
		if (count == 5)
		{
			this->user = NULL;
			CheckUser = false;
			return CheckUser;
		}
	}
}

void Terminal::UserWrite()
{
	usersearch->UserWrite(this->user);
}

void Terminal::Deposite(double _deposite)
{
	if (this->user == NULL)
		cout << "Ошибка!\n";
	else
	{
		if (_deposite < 0)
			cout << "Недостаточно средств для пополнения кошелька\n";
		else
		{
			this->user->Deposite(_deposite);
			cout << "Депозит успешно выполнен\n";
			this->UserWrite();
		}
	}
}

void Terminal::Withdraw(double _withdraw)
{
	if (this->user == NULL)
		cout << "Ошибка!\n";
	else
	{
		if (_withdraw > 0)
		{
			int amount = this->user->GetAmount();
			int temp = amount - _withdraw;
			if (temp < 0)
				cout << "Операция невозможна\n";
			else
			{
				cout << "Операция прошла успешно \n";
				this->user->WithDraw(_withdraw);
				this->UserWrite();
			}
		}
		else
		{
			cout << "Операция не прошла!\n";
		}
	}
}

void Terminal::ShowInfo()
{
	cout << "Ваш ид: " << user->GetNumber() << endl;
	cout << "Балланс: " << user->GetAmount() << endl;
}

void Terminal::EjectCard()
{
	user = NULL;
}

void Terminal:: LoadCash(BanknoteVault** _banknote)
{
	CashKeeper = _banknote;
}

bool Terminal:: CheckForIssuingBanknotes(int _WithdrawCountQuantity)
{
	if (_WithdrawCountQuantity % 50 == 0)
	{	
			int tempResultThousandth = _WithdrawCountQuantity / 1000; //Результат тысячных
			int tempResultHundredth = _WithdrawCountQuantity % 1000; // Результат сотых
			int NumbersOfFiveThousandBills = tempResultThousandth / 5; // кол-во купюр по 5к
			int NumbersOfOneThousandBills = tempResultThousandth % 5; // кол-во купюр по тысячи
			int MoreThanFiveHundredOrLess = tempResultHundredth / 100; // Результат для того чтоб понять, остаток больше 500 или меньше
			int CheckForTheFiftiethNote = tempResultHundredth % 100; // Результат проверки на 50 рублей в конце
			int NumbersOfFiveHundredBills = MoreThanFiveHundredOrLess / 5; // кол-во купюр по 500
			int NumbersOfOneHundredBills = MoreThanFiveHundredOrLess % 5; // кол-во купюр по сотке

			for (int i = 0; i < NumbersOfFiveThousandBills; i++)
				CashKeeper[4]->CurrentNubmers--; // 5k
			for (int i = 0; i < NumbersOfOneThousandBills; i++)
				CashKeeper[3]->CurrentNubmers--; // 1k
			for (int i = 0; i < NumbersOfFiveHundredBills; i++)
				CashKeeper[2]->CurrentNubmers--; // 500units
			for (int i = 0; i < NumbersOfOneHundredBills; i++)
				CashKeeper[1]->CurrentNubmers--; // 100units
			for (int i = 0; i < CheckForTheFiftiethNote; i++)
				CashKeeper[0]->CurrentNubmers--; // 50units

			cout << "Операция прошла успешна!\n";
			if (this->user->GetNumber() == 13)
			{
					cout << "Банкнот по 5к: " << NumbersOfFiveThousandBills << "\n";
					cout << "Банкнот по 1к: " << NumbersOfOneThousandBills << "\n";
					cout << "Банкнот по 500: " << NumbersOfFiveHundredBills << "\n";
					cout << "Банкнот по 100: " << NumbersOfOneHundredBills << "\n";
					cout << "Банкнот по 50: " << CheckForTheFiftiethNote << "\n";
			}
			return true;
	}
	else
	{
		cout << "Неправильная сумма ввода\n";
		return false;
	}
}