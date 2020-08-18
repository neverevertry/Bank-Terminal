#define _CRT_SECURE_NO_WARNINGS
#include "Terminal2.h"
#include <iostream>
#include "User2.h"

using namespace std;

Terminal2:: Terminal2(string _NameTerminal)
{
	NameTerminal = _NameTerminal;
}

void Terminal2::GetUser(long _id)
{
	UserBase2* _usersearche = new UserBase2();
	this->user = _usersearche->SearchUser(_id);

	int count = 0;
	bool flag = false;
	
	while (!flag)
	{
		if (this->user == NULL)
		{
			int id;
			cout << "�������� ��, ��������� �������\n";
			cin >> id;
			this->user = _usersearche->SearchUser(id);
			count++;
			flag = false;
		}
		else
		{
			cout << "����������� ������ �������!\n";
			flag = true;
		}
		if (count == 5)
		{
			this->user = NULL;
			break;
		}
	}
}

void Terminal2::UserWrite()
{
	UserBase2* _userwrite = new UserBase2();
	_userwrite->UserWrite(this->user);
}

void Terminal2::Deposite(double _deposite)
{
	if (_deposite < 0)
		cout << "������������ ������� ��� ���������� ��������\n";
	else
	{
		this->user->Deposite(_deposite);
		cout << "������� ������� ��������\n";
	}
}

void Terminal2::Withdraw(double _withdraw)
{
	if (_withdraw > 0)
	{
		int amount = this->user->GetAmount();
		int temp = amount - _withdraw;
		if (temp < 0)
		{
			cout << "�������� ����������\n";
			cout << "������� ������� " << amount << endl;
			cout << "�� ��������� ����� " << _withdraw << endl;
		}
		else
		{
			cout << "�������� ������ ������� \n";
			this->user->WithDraw(_withdraw);
		}
	}
	else
	{
		cout << "�������� �� ������!\n";
	}
}

void Terminal2::ShowInfo()
{
	cout << "��� ��: " << user->GetNumber() << endl;
	cout << "�������: " << user->GetAmount() << endl;
}

void Terminal2::EjectCard()
{
	user = NULL;
}

