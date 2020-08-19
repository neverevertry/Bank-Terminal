#include "User2.h"
#include "UserBase2.h"
#include <iostream>
using namespace std;

class Terminal
{
private:
	string NameTerminal;
	UserBase* usersearch;
	User* user;
public:
	Terminal(string _NameTerminal);

	bool GetUser(long _id);
	
	void UserWrite();

	void Deposite(double _deposite);

	void Withdraw(double _withdraw);

	void ShowInfo();

	void EjectCard();
};

