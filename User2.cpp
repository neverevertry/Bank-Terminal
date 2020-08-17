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
			cout << "������������ ������� ��� ���������� ��������\n";
		else
		{
			amount += _deposite;
			cout << "������� ������� ��������\n";
		}
	}

	void User2:: Withdraw(double _withdraw)
	{
		if (_withdraw > 0)
		{
			int temp = amount - _withdraw;
			if (temp < 0)
				cout << "�� ������� �� ����� ���� �������������� ��������!\n";
			else
			{
				cout << "�������� ������ ������� \n";
				amount -= _withdraw;
			}
		}
		else
		{
			cout << "�������� �� ������!\n";
		}
	}

	void User2:: ShowInfo()
	{
		cout << "��� ��: " << NumbCart << endl;
		cout << "�������: " << amount << endl;
	}

	long User2:: GetNumber()
	{
		return NumbCart;
	}
