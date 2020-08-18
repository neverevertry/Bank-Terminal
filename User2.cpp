#include "User2.h"
#include <iostream>

using namespace std;

	User2:: User2 (long _NumbCart, int _amount)
	{
		NumbCart = _NumbCart;
		amount = _amount;
	}

	long User2:: GetNumber()
	{
		return NumbCart;
	}

	int User2::GetAmount()
	{
		return amount;
	}

	void User2:: Deposite (int _add)
	{
		amount += _add;
	}

	void User2::WithDraw(int _TakeOff)
	{
		amount -= _TakeOff;
	}
