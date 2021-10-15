#include "Order_Header.h"
#include <string>
using namespace std;


vector<string> Users = { "admin", "user" };
vector<string> Passwords = { "password", "qaqa" };

bool StartPage() {
	int a;
	system("cls");

	cout << "Введите число\nВойти: 1" << endl;
	cout << "\nВыход: 2" << endl;
	cin >> a;
	switch (a) {
	case 1: {
		system("cls");
		return true;
	}
	default: {
		return false;
	}
	}
	return false;
}

bool UserCheck(string& Username, string& Password, int& p) {
	system("cls");
	cout << "Осталось попыток: " << p - 1 << endl;

	for (int i = 0; i < Users.size(); i++) {
		for (int j = 0; j < Passwords.size(); j++) {
			if (Users[i] == Username) {
				if (Passwords[j] == Passwords[i] && Passwords[j] == Password) {
					return true;
				}
				
			}
			
		}
	}
	return false;
}
