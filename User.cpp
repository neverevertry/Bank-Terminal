#include "User.h"
#include <iostream>

using namespace std;

	User:: User (long _InsertCard, int _amount)
	{
		InsertCard = _InsertCard;
		amount = _amount;
	}

	long User:: GetNumber()
	{
		return InsertCard;
	}

	int User::GetAmount()
	{
		return amount;
	}

	void User:: Deposite (int _add)
	{
		amount += _add;
	}

	void User::WithDraw(int _TakeOff)
	{
		amount -= _TakeOff;
	}
