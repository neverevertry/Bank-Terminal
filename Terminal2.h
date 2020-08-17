#include "User2.h"
#include <iostream>
using namespace std;

class Terminal2
{
private:
	string NameTerminal;
public:

	Terminal2(string _NameTerminal);
	
	void WriteUser(User2* user);

	User2* SearcheUser(long _id);

	User2* CheckUser(Terminal2* one, const int money);
};

