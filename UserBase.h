#pragma once
#include "User.h"
class UserBase
{
public:
	void UserWrite(User* user);

	User* GetUserById(long _id);
};