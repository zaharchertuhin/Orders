#include "Order.h"
using namespace std;

void Edit_Users(vector<Users>& signIn) {
	bool key = true;
	while (key) {
		int i = 1;
		system("cls");
		cout << "��� ������������: "<< endl;
		for (Users x : signIn) {
			string psw = "";
			for (int i = 0; i < x.password.size(); i++) {
				psw += "*";
			}
			cout << i << ")\n�����: " << x.login << "\n������: " << psw << "\n������� �������: " << x.status << "\n";
			i++;
		}
		int a;
		cout << "\n\n������� ��������: \n" << endl;
		cout << "\t1) �������� �����" << "\n\t2) �������� ������" << "\n\t3) �������� �������" << "\n\t4) ������� ������������" << "\n\t5) �������� ������������: " << "\n\t6) ���������� ������" << "\n\t7) �����" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			system("cls");
			int j;
			cout << "������� ����� ������" << endl;
			cin >> j;
			j--;
			cout << "������� ����� �����: ";
			cin >> signIn[j].login;
			break;
		}
		case 2:
		{
			system("cls");
			int j;
			cout << "������� ����� ������" << endl;
			cin >> j;
			j--;
			cout << "������� ����� ������: ";
			cin >> signIn[j].password;
			break;
		}
		case 3:
		{
			system("cls");
			int j;
			cout << "������� ����� ������" << endl;
			cin >> j;
			j--;
			cout << "������� ����� �������(���������� ��������: 1): ";
			cin >> signIn[j].status;
			break;
		}
		case 4:
		{
			system("cls");
			int j;
			cout << "������� ����� ������" << endl;
			cin >> j;
			signIn.erase(signIn.begin() + j - 1);
			break;
		}
		case 5: {
			system("cls");
			Users user;
			cout << "������� ����� �����: ";
			cin >> user.login;
			cout << "������� ����� ������: ";
			cin >> user.password;
			cout << "������� ����� �������(���������� ��������: 1): ";
			cin >> user.status;
			signIn.push_back(user);
			break;
		}
		case 6: {
			system("cls");
			int j;
			cout << "������� ����� ������" << endl;
			cin >> j;
			j--;
			cout << "\n �����: " << signIn[j].login << "\n ������: " << signIn[j].password << endl;
			system("pause");
			break;
		}
		default:
			key = false;
			break;
		}
	}
}

void Save_Users(vector<Users>& signIn) {
	fstream lgn("login.txt");
	if (lgn.is_open()) {
		for (Users x : signIn) {
			if (x.status != 0) {
				lgn << x.login << "\n" << x.password << "\n" << x.status << "\n*\n";
			}

		}
	}
	lgn.close();
}

//Users Find_User(vector<Users>& signIn, int& num) {
//	Users user;
//	int i = 1;
//	for (Users x : signIn) {
//		if (num = i) {
//			user = x;
//			return user;
//		}
//		i++;
//	}
//}