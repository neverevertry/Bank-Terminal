#define _CRT_SECURE_NO_WARNINGS
#include "UserBase2.h"
#include "Terminal2.h"
#include <iostream>


using namespace std;

void UserBase2 :: UserWrite(User2* user)
{
	FILE* USERINFO = fopen("UserInfo.dat", "ab");
	if (USERINFO == NULL)
		cout << "файл не найден\n";
	else
		fwrite(user, sizeof(User2), 1, USERINFO);

	fclose(USERINFO);
}

User2* UserBase2:: SearchUser(long _id)
{
	User2* user = (User2*)malloc(sizeof(User2));
	FILE* USERINFO = fopen("UserInfo.dat", "r");
	if (USERINFO == NULL)
	{
		cout << "файл не найден!\n";
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