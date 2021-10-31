#include "Order.h"
using namespace std;

void Edit_Users(vector<Users>& signIn, int& usr_chk) {
	bool key = true;
	while (key) {
		int i = 1;
		system("cls");
		cout << "Все Пользователи: " << endl;
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
		cout << "\t1) Изменить Логин" << "\n\t2) Изменить пароль" << "\n\t3) Изменить уровень" << "\n\t4) Удалить пользователя" << "\n\t5) Добавить пользователя: " << "\n\t6) Посмотреть пароли" << "\n\t7) Сохранить и Выйти" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			if (usr_chk >= 3) {
				system("cls");
				int j;
				cout << "Введите номер Логина" << endl;
				cin >> j;
				j--;
				cout << "Введите новый логин: ";
				cin >> signIn[j].login;
				break;
			}
			else {
				cout << "У вас нет доступа" << endl;
				system("pause");
				break;
			}
		}
		case 2:
		{
			if (usr_chk >= 3) {
				system("cls");
				int j;
				cout << "Введите номер Логина" << endl;
				cin >> j;
				j--;
				cout << "Введите новый пароль: ";
				cin >> signIn[j].password;
				break;
			}
			else {
				cout << "У вас нет доступа" << endl;
				system("pause");
				break;
			}
		}
		case 3:
		{
			if (usr_chk >= 3) {
				bool flag = true;
				system("cls");
				int j;
				cout << "Введите номер Логина" << endl;
				cin >> j;
				j--;
				while (flag) {
					int lvl = 0;
					cout << "Введите новый уровень(Наименьшее значение: 1): ";
					cin >> lvl;
					if (lvl > 0) {
						signIn[j].status = lvl;
						flag = false;
					}
					else {
						cout << "Wrong level!" << endl;
						signIn[j].status = 1;
					}
				}
				break;
			}
			else {
				cout << "У вас нет доступа" << endl;
				system("pause");
				break;
			}
		}
		case 4:
		{
			if (usr_chk >= 3) {
				system("cls");
				int j;
				cout << "Введите номер Логина" << endl;
				cin >> j;
				signIn.erase(signIn.begin() + j - 1);
				break;
			}
			else {
				cout << "У вас нет доступа" << endl;
				system("pause");
				break;
			}
		}
		case 5: {
			if (usr_chk >= 2) {
				system("cls");
				Users user;
				int stat = 1;
				cout << "Введите новый логин: ";
				cin >> user.login;
				cout << "Введите новый пароль: ";
				cin >> user.password;

				while (true) {
					cout << "Введите новый уровень(Наименьшее значение: 1): ";
					cin >> stat;
					if (stat <= usr_chk) {
						user.status = stat;
						break;
					}
					else {
						cout << "Wrong level!" << endl;
						system("pause");
					}
				}

				signIn.push_back(user);
				break;
			}
			else {
				cout << "У вас нет доступа" << endl;
				system("pause");
				break;
			}
		}
		case 6: {
			if (usr_chk >= 3) {
				system("cls");
				int j;
				cout << "Введите номер Логина" << endl;
				cin >> j;
				j--;
				cout << "\n Логин: " << signIn[j].login << "\n Пароль: " << signIn[j].password << endl;
				system("pause");
				break;
			}
			else {
				cout << "У вас нет доступа" << endl;
				system("pause");
				break;
			}
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