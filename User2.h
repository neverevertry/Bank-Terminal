#pragma once
class User2
{
private:
	double amount;
	long NumbCart;
public:

	User2(long _NumbCart, int _amount);

	long GetNumber();
	int GetAmount();
	void Deposite(int _add);
	void WithDraw(int _TakeOff);
};

