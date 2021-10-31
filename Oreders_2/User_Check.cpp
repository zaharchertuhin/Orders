#include "Order.h"
#include <string>
using namespace std;

Users SignUp() {
	system("cls");
	Users User;
	fstream lgn("login.txt", ios::app);
	string lg, ps;
	cout << "Введите логин: ";
	(cin >> lg).get();
	cout << "Введите пароль:";
	(cin >> ps).get();
	User.login = lg;
	User.password = ps;
	if (lgn.is_open()) {
		lgn <<"\n" << User.login << "\n" << User.password << "\n*";
	}
	lgn.close();
	return User;
}



int StartPage() {
	int a;
	system("cls");
	cout << "Введите число\nВойти: 1\nРегистрация: 2\nВыход: 3" << endl;
	cin >> a;
	switch (a) {
	case 1: {
		system("cls");
		return 0;
	}
	case 2:
	{
		return 2;
	}
	case 3: {
		return 1;
	}
	default: {
		cout << "Месье, вы дэбил, давайте по-новой." << endl;
		return 3;
	}
	}

}

int UserCheck(string& Username, string& Password, vector<Users> Login) {
	system("cls");
	for (int i = 0; i < Login.size(); i++) {
		if (Login[i].login == Username && Login[i].password == Password) {
			return Login[i].status;
		}
	}

	return 0;
}

vector<Users> Login() {
	vector<Users> User;
	ifstream lgn("login.txt");
	string data;
	if (lgn.is_open()) {
		while (!lgn.eof())
		{
			Users user;
			getline(lgn, data, '\n');
			user.login = data;
			getline(lgn, data, '\n');
			user.password = data;
			getline(lgn, data, '\n');
			user.status = atoi(data.c_str());
			getline(lgn, data, '\n');
			
			User.push_back(user);
		}
		User.pop_back();
		return User;
	}
}