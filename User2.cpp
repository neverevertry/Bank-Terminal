#include "User2.h"
#include <iostream>

using namespace std;

	User2:: User2 (long _NumbCart, int _amount)
	{
		NumbCart = _NumbCart;
		amount = _amount;
	}

	void User2:: Deposite(double _deposite)
	{
		if (_deposite < 0)
			cout << "Недостаточно средств для пополнения кошелька\n";
		else
		{
			amount += _deposite;
			cout << "Депозит успешно выполнен\n";
		}
	}

	void User2:: Withdraw(double _withdraw)
	{
		if (_withdraw > 0)
		{
			int temp = amount - _withdraw;
			if (temp < 0)
				cout << "На балансе не может быть отрицательного значения!\n";
			else
			{
				cout << "Операция прошла успешно \n";
				amount -= _withdraw;
			}
		}
		else
		{
			cout << "Операция не прошла!\n";
		}
	}

	void User2:: ShowInfo()
	{
		cout << "Ваш ид: " << NumbCart << endl;
		cout << "Балланс: " << amount << endl;
	}

	long User2:: GetNumber()
	{
		return NumbCart;
	}
