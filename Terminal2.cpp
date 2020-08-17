#define _CRT_SECURE_NO_WARNINGS
#include "Terminal2.h"
#include <iostream>
#include "User2.h"

using namespace std;

Terminal2:: Terminal2(string _NameTerminal)
{
	NameTerminal = _NameTerminal;
}

void Terminal2::WriteUser(User2* user)
{
	FILE* USERINFO = fopen("UserInfo.dat", "ab");
	if (USERINFO == NULL)
		cout << "���� �� ������\n";
	else
		fwrite(user, sizeof(User2), 1, USERINFO);

	fclose(USERINFO);
}

User2* Terminal2 :: SearcheUser(long _id)
{
	//�.�. ��� User* user = NULL ������ ���������� �� ���������� �� � ���������� ������, ��-����� ������� ������ ������� � ������� ������� malloc ����� � 
	User2* user = (User2*)malloc(sizeof(User2));
	FILE* USERINFO = fopen("UserInfo.dat", "r");
	if (USERINFO == NULL)
	{
		cout << "���� �� ������!\n";
	}
	else
	{
		while (!feof(USERINFO))
		{
			fread(user, sizeof(User2), 1, USERINFO);
			if (user->GetNumber() == _id)
			{
				return user;
				fclose(USERINFO);
			}
		}
	}

	fclose(USERINFO);
	return NULL;
}

User2* Terminal2:: CheckUser(Terminal2* one, const int money)
{
	bool flag = false;
	while (!flag)
	{
		long id;
		cin >> id;
		if (one->SearcheUser(id) == NULL)
		{
			cout << "������ ID, ��������� �������.\n";
			flag = false;
		}
		else
		{
			cout << "�� ������� ����� �� ���� ������� ����\n";
			flag = true;
			return one->SearcheUser(id);
		}
	}
}