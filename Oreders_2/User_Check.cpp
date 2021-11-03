
#include "Order.h"
#include <string>
using namespace std;

string Encode(string& Text);
string Decode(string& Text);

Users SignUp() {
	system("cls");
	Users User;
	fstream lgn("login.txt", ios::app);
	cout << "������� �����: ";
	(cin >> User.login).get();
	cout << "������� ������:";
	(cin >> User.password).get();
	if (User.login == "admin") {
		User.status = 3;
	}
	else User.status = 1;
	if (lgn.is_open()) {
		lgn  << User.login << "\n" << Encode(User.password) << "\n" << User.status << "\n*\n";
	}
	lgn.close();
	return User;
}



int StartPage() {
	string a;
	system("cls");
	cout << "������� �����\n�����: 1\n�����������: 2\n�����: 3" << endl;
	cin >> a;
	if (isdigit(a[0])) {
		switch (stoi(a)) {
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
			cout << "�����, �� �����, ������� ��-�����." << endl;
			return 3;
		}
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
			user.password = Decode(data);
			getline(lgn, data, '\n');
			user.status = atoi(data.c_str());
			getline(lgn, data, '\n');
			User.push_back(user);
		}
		User.pop_back();
		
		return User;
	}
	lgn.close();

}