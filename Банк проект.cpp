#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

class User
{
private:
	double amount;
	long NumbCart;
public:
	
	User(long _NumbCart, int _amount)
	{
		NumbCart = _NumbCart;
		amount = _amount;
	}

	void Deposite(double _deposite)
	{
		if (_deposite < 0)
			cout << "Недостаточно средств для пополнения кошелька\n";
		else
		{
			amount += _deposite;
			cout << "Депозит успешно выполнен\n";
		}
	}

	void Withdraw(double _withdraw)
	{
		if (_withdraw > 0)
		{
			int temp = amount - _withdraw;
			if (temp < 0)
				cout << "На балансе не может быть отрицательного значения!\n";
			else
			{
				cout << "Операция прошла успешно \n";
				amount -= _withdraw;
			}
		}
		else
		{
			cout << "Операция не прошла!\n";
		}
	}

	void ShowInfo()
	{
		cout << "Ваш ид: " << NumbCart << endl;
		cout << "Балланс: " << amount << endl;
	}

	long GetNumber()
	{
		return NumbCart;
	}
};

class Terminal
{
public:
	void WriteUser(User* user)
	{
		FILE* USERINFO = fopen("UserInfo.dat", "ab");
		if (USERINFO == NULL)
			cout << "файл не найден\n";
		else
			fwrite(user, sizeof(User), 1, USERINFO);

		fclose(USERINFO);
	}

	User* SearcheUser(long _id)
	{
		//Т.к. при User* user = NULL память фактически НЕ выделяется то и записывать некуда, по-этому создаем память вручную с помощью функции malloc языка С 
		User* user = (User*)malloc(sizeof(User));
		FILE* USERINFO = fopen("UserInfo.dat", "r");
		if (USERINFO == NULL)
		{
			cout << "файл не найден!\n";
		}		
		else
		{
			while (!feof(USERINFO))
			{
				fread(user, sizeof(User), 1, USERINFO);
				if (user->GetNumber() == _id)
				{
					return user;
					fclose(USERINFO);
				}
			}
		}
		
		fclose(USERINFO);
		return NULL;	
	}
};

User* CheckUser(Terminal* one, const int money)
{
	long AutoOrRegister;
	cout << "Здравствуйте, для того чтоб зарегистрироваться, нажмите 1\n Для того чтоб авторизироваться, нажмите 2\n";
	cin >> AutoOrRegister;
	if (AutoOrRegister == 1)
	{
		long id;
		cin >> id;
		cout << "Вы успешно зарегистрировались, ваш личный ИД " << id << "так же бонусное пополнение в размере " << money << endl;
		User* user = new User(id, money);
		return user;
	}
	else
	{
		bool flag = false;
		while (!flag)
		{
			long id;
			cin >> id;
			if (one->SearcheUser(id) == NULL)
			{
				cout << "Ошибка ID, повторите попытку.\n";
				flag = false;
			}
			else
			{
				cout << "Вы успешно зашли на свой лицевой счет\n";
				flag = true;	
				return one->SearcheUser(id);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int money = 500;
	long id;
	bool flag;

	Terminal* one = new Terminal();
	User* user = CheckUser(one, money);
	
		int menu;
		do
		{
			cout << "1.Положить наличные на счет\n";
			cout << "2.Снять наличные со счета\n";
			cout << "3.Информация\n";
			cout << "0.Выход\n";
			cin >> menu;

			switch (menu)
			{
			case 1:
			{
				user->Deposite(100);
				one->WriteUser(user);
			}; break;
			case 2:
			{
				user->Withdraw(50);
				one->WriteUser(user);
			}; break;
			case 3:
			{
				user->ShowInfo();
			}; break;
			case 0:
			{
				break;
			}; break;
			}
		} while (menu != 0);

	system("pause");
	return 0;
}