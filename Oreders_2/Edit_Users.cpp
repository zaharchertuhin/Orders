#include "Order.h"
#include <string.h>
using namespace std;

string base64_encode(std::string const& s, bool url);
int isInt();

//����� ����������, ���� ��� ���� ���� �� ������, � ���������� �����, � ����� ��� ��� ��������� �������� ���������

int FindUser(vector<Users>& Registered) {
	system("cls");
	string j;
	cout << "������� ����� ������������, �������� ������� ��������." << endl;
	cin >> j;
	for (int i = 0; i < Registered.size(); i++) {
		if (Registered[i].login == j) return i;

	}
	
}


string EditLogin() {
	system("cls");
	string login;
	cout << "������� ����� �����: ";
	cin >> login;
	return login;
}

string EditPswrd() {
	system("cls");
	while (true)
	{
		string psw1, psw2;
		cout << "������� ����� ������: ";
		cin >> psw1;
		cout << "\n\n��������� ����� ������: ";
		cin >> psw2;
		if (psw1 == psw2) { return psw1; break; }
		else { cout << "\n\n������ �� ���������. ��������� ��� ���:" << endl; system("pause"); }
	}
}

int EditLvl() {
	system("cls");
	while (true) {
		int lvl = 0;
		cout << "������� ����� ������� �� 1 �� 3: ";
		cin >> lvl;
		if (lvl > 0 && lvl < 4) {
			return lvl;
			break;
		}
		else {
			cout << "Wrong level!" << endl;
			system("pause");
		}
	}
}

Users NewUser() {
	system("cls");
	Users user;
	user.login = EditLogin();
	user.password = EditPswrd();
	user.status = EditLvl();
	return user;
}

void Save_Users(vector<Users>& Registered) {
	fstream lgn("login.txt");
	if (lgn.is_open()) {
		for (Users x : Registered) {
			if (x.status != 0) {
				lgn << x.login << "\n" << base64_encode(x.password, true) << "\n" << x.status << "\n*\n";
			}

		}
	}
	lgn.close();
}