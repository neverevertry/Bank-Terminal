#include "User2.h"
#include "UserBase2.h"
#include <iostream>
using namespace std;

class Terminal2
{
private:
	string NameTerminal;
	UserBase2* usersearch;
	User2* user;
public:
	Terminal2(string _NameTerminal);

	void GetUser(long _id);

	void CheckUser(long _id);
	
	void UserWrite();

	void Deposite(double _deposite);

	void Withdraw(double _withdraw);

	void ShowInfo();

	void EjectCard();
};

