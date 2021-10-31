#include "Order.h"
using namespace std;

void Edit_Users(vector<Users>& signIn) {
	bool key = true;
	while (key) {
		int i = 1;
		system("cls");
		cout << "Все Пользователи: "<< endl;
		for (Users x : signIn) {
			string psw = "";
			for (int i = 0; i < x.password.size(); i++) {
				psw += "*";
			}
			cout << i << ")\nЛогин: " << x.login << "\nПароль: " << psw << "\nУровень допуска: " << x.status << "\n";
			i++;
		}
		int a;
		cout << "\n\nВведите действие: \n" << endl;
		cout << "\t1) Изменить Логин" << "\n\t2) Изменить пароль" << "\n\t3) Изменить уровень" << "\n\t4) Удалить пользователя" << "\n\t5) Добавить пользователя: " << "\n\t6) Посмотреть пароли" << "\n\t7) Выйти" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			system("cls");
			int j;
			cout << "Введите номер Логина" << endl;
			cin >> j;
			j--;
			cout << "Введите новый логин: ";
			cin >> signIn[j].login;
			break;
		}
		case 2:
		{
			system("cls");
			int j;
			cout << "Введите номер Логина" << endl;
			cin >> j;
			j--;
			cout << "Введите новый пароль: ";
			cin >> signIn[j].password;
			break;
		}
		case 3:
		{
			system("cls");
			int j;
			cout << "Введите номер Логина" << endl;
			cin >> j;
			j--;
			cout << "Введите новый уровень(Наименьшее значение: 1): ";
			cin >> signIn[j].status;
			break;
		}
		case 4:
		{
			system("cls");
			int j;
			cout << "Введите номер Логина" << endl;
			cin >> j;
			signIn.erase(signIn.begin() + j - 1);
			break;
		}
		case 5: {
			system("cls");
			Users user;
			cout << "Введите новый логин: ";
			cin >> user.login;
			cout << "Введите новый пароль: ";
			cin >> user.password;
			cout << "Введите новый уровень(Наименьшее значение: 1): ";
			cin >> user.status;
			signIn.push_back(user);
			break;
		}
		case 6: {
			system("cls");
			int j;
			cout << "Введите номер Логина" << endl;
			cin >> j;
			j--;
			cout << "\n Логин: " << signIn[j].login << "\n Пароль: " << signIn[j].password << endl;
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