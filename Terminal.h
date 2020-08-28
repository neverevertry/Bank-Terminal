#include "User.h"
#include "UserBase.h"
#include <iostream>
#include "BanknoteVault.h"
using namespace std;

class Terminal
{
private:
	string NameTerminal;
	UserBase* usersearch;
	User* user;
	BanknoteVault** CashKeeper;
public:
	Terminal(string _NameTerminal);

	bool GetUserById(long _id);
	
	void UserWrite();

	void Deposite(double _deposite);

	void Withdraw(double _withdraw);

	void ShowInfo();

	void EjectCard();

	void LoadCash(BanknoteVault** _banknote);

	bool CheckForIssuingBanknotes(int _WithdrawCountQuantity);


};

