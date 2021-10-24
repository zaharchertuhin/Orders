#include "Order.h"
#include <string>
using namespace std;


bool StartPage() {
	int a;
	system("cls");
	cout << "Введите число\nВойти: 1\nВыход: 2" << endl;
	cin >> a;
	switch (a) {
	case 1: {
		system("cls");
		return true;
	}
	case 2: {
		return false;
	}
	default: {
		cout << "Месье, вы дэбил, давайте по-новой." << endl;
		return false;
	}
	}

}

bool UserCheck(string& Username, string& Password, vector<Users> Login) {
	system("cls");
	for (int i = 0; i < Login.size(); i++) {
		if (Login[i].login == Username && Login[i].password == Password) {
			return true;
		}
	}
	return false;
}

vector<Users> Login() {
	vector<Users> User;

	/*fstream lgn("login.txt");
	fstream pswrd("passwords.txt");
	string lg, ps;
	while (!lgn.eof() && !pswrd.eof())
	{
		Users user;
		getline(lgn, lg);
		user.login = lg;
		cout << lg<< endl;
		getline(pswrd, ps);
		user.password = ps;
		cout << ps << endl;
		User.push_back(user);
	}*/

	system("pause");
	return User;
}