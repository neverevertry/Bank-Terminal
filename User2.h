#pragma once
class User
{
private:
	double amount;
	long InsertCard;
public:

	User(long _InsertCard, int _amount);

	long GetNumber();
	int GetAmount();
	void Deposite(int _add);
	void WithDraw(int _TakeOff);
};

