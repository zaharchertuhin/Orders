#include "Order.h"
#include <string>
using namespace std;

string base64_encode(std::string const& s, bool url);
int FindUser(vector<Users>& Registered);
bool UserCheck(string& Username, string& Password, vector<Users>& Login);
bool Authorization(vector<Users>& signIn);
string EditLogin();
string EditPswrd();
int EditLvl();
Users NewUser();
int isInt();

Users Registration(vector<Users> &Login) {
	system("cls");
	Users User;
	bool key = true;
	fstream lgn("login.txt", ios::app);
	while (key)
	{
		cout << "������� �����: ";
		(cin >> User.login).get();
		if (Login.size() == 0)key = false;
		else {
			for (Users U : Login) {
				if (U.login == User.login) {
					cout << "\n����� ������������ ��� ����������." << endl;
					key = true;

				}
				else {
					key = false;
				}
			}
		}
	}
	cout << "������� ������:";
	(cin >> User.password).get();
	if (User.login == "admin") {
		User.status = 3;
	}
	else User.status = 1;
	if (lgn.is_open()) {
		lgn  << User.login << "\n" << base64_encode(User.password, true) << "\n" << User.status << "\n*\n";
	}
	lgn.close();
	return User;
}

bool StartPage(vector<Users>& signIn) {
	while (true)
	{
		system("cls");
		cout << "������� �����\n�����: 1\n�����������: 2\n�����: 3" << endl;
		int a = isInt();
		switch (a) {
		case 1: {
			system("cls");
			return Authorization(signIn);
			break;
		}
		case 2:
		{
			signIn.push_back(Registration(signIn));
			break;
		}
		case 3: {
			exit(0);
		}
		default: {
			cout << "�����, �� �����, ������� ��-�����." << endl;
			system("pause");
			break;
		}
		}
	}
}

bool Authorization(vector<Users>& signIn) {
	string Username, Password;
	cout << "Login:" << endl;
	cin >> Username;
	cout << "Password:" << endl;
	cin >> Password;
	Password = base64_encode(Password, true);
	return UserCheck(Username, Password, signIn);
}

bool UserCheck(string& Username, string& Password, vector<Users> &Login) {
	system("cls");
	for (int i = 0; i < Login.size(); i++) {
		if (Login[i].login == Username && Login[i].password == Password) {
			return true;
		}
	}
	return false;
}

vector<Users> Logins() {
	vector<Users> users;
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
			users.push_back(user);
		}
		users.pop_back();
		return users;
	}
	lgn.close();
}

void Edit_Users(vector<Users>& Registered) {
	bool key = true;
	while (key) {
		int i = 1;
		system("cls");
		cout << "��� ������������: " << endl;
		for (Users x : Registered) {
			cout << i << ") �����: " <<
				x.login << "\n������: " <<
				x.password.replace(0, x.password.size(), "********") <<
				"\n������� ������� : " << x.status << "\n\n";
			i++;
		}
		
		cout << "\n\n������� ��������: \n" << endl;
		cout << "\t1) �������� �����" <<
			"\n\t2) �������� ������" <<
			"\n\t3) �������� �������" <<
			"\n\t4) ������� ������������" <<
			"\n\t5) �������� ������������ " <<
			"\n\t6) ��������� � �����" << endl;
		int a = isInt();
		switch (a)
		{
		case 1:
		{
			int id = FindUser(Registered);
			Registered[id].login = EditLogin();
			break;
		}
		case 2:
		{
			int id = FindUser(Registered);
			string psw = EditPswrd();
			Registered[id].password = base64_encode(psw, true); break; 
			break;
		}
		case 3:
		{
			int id = FindUser(Registered);
			Registered[id].status = EditLvl();
			break;
		}
		case 4:
		{
			int id = FindUser(Registered);
			system("cls");
			Registered.erase(Registered.begin() + id);
			cout << "������������ ������." << endl;
			system("pause");
			break;
		}
		case 5: 
		{
			Registered.push_back(NewUser());
			break;
		}

		case 6: {
			key = false;
			break;
		}
		default:
			cout << "�����, �� �����, ������� ��-�����." << endl;
			break;
		}
	}
}