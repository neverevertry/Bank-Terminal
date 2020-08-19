#pragma once
#include "User2.h"
class UserBase
{
public:
	void UserWrite(User* user);

	User* GetUserById(long _id);
};

