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
			cout << "�������� ��, ��������� �������\n";
			cin >> id;
			this->user = usersearch->GetUserById(id);
			count++;
			CheckUser = false;
		}
		else
		{
			cout << "����������� ������ �������!\n";
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
		cout << "������!\n";
	else
	{
		if (_deposite < 0)
			cout << "������������ ������� ��� ���������� ��������\n";
		else
		{
			this->user->Deposite(_deposite);
			cout << "������� ������� ��������\n";
			this->UserWrite();
		}
	}
}

void Terminal::Withdraw(double _withdraw)
{
	if (this->user == NULL)
		cout << "������!\n";
	else
	{
		if (_withdraw > 0)
		{
			int amount = this->user->GetAmount();
			int temp = amount - _withdraw;
			if (temp < 0)
				cout << "�������� ����������\n";
			else
			{
				cout << "�������� ������ ������� \n";
				this->user->WithDraw(_withdraw);
				this->UserWrite();
			}
		}
		else
		{
			cout << "�������� �� ������!\n";
		}
	}
}

void Terminal::ShowInfo()
{
	cout << "��� ��: " << user->GetNumber() << endl;
	cout << "�������: " << user->GetAmount() << endl;
}

void Terminal::EjectCard()
{
	user = NULL;
}