#define _CRT_SECURE_NO_WARNINGS
#include "Terminal2.h"
#include <iostream>
#include "User2.h"

using namespace std;

Terminal:: Terminal(string _NameTerminal)
{
	NameTerminal = _NameTerminal;
	user = NULL;
	usersearch = new UserBase();
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