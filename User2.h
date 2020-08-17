#pragma once
class User2
{
private:
	double amount;
	long NumbCart;
public:

	User2(long _NumbCart, int _amount);

	void Deposite(double _deposite);

	void Withdraw(double _withdraw);

	void ShowInfo();

	long GetNumber();
};

