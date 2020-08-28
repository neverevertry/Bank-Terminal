#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "UserBase.h"
#include "Terminal.h"
#include <iostream>

using namespace std;

void UserBase :: UserWrite(User* user)
{
	FILE* USERINFO = fopen("UserInfo.dat", "ab");
	if (USERINFO == NULL)
		cout << "файл не найден\n";
	else
		fwrite(user, sizeof(User), 1, USERINFO);

	fclose(USERINFO);
}

User* UserBase::GetUserById(long _id)
{
	User* user = (User*)malloc(sizeof(User));
	FILE* USERINFO = fopen("UserInfo.dat", "r");
	if (USERINFO == NULL)
	{
		cout << "файл не найден!\n";
	}
	else
	{
		while (!feof(USERINFO))
		{
			fread(user, sizeof(User), 1, USERINFO);
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