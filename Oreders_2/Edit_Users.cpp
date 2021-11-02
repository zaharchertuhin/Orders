#include "Order.h"
#include <string.h>
using namespace std;

string Encode(string& Text);
string Decode(string& Text);

void Edit_Users(vector<Users>& signIn, int& usr_chk) {
	bool key = true;
	while (key) {
		int i = 1;
		system("cls");
		cout << "Все Пользователи: " << endl;
		for (Users x : signIn) {
			cout << i << ")\nЛогин: " << 
				x.login << "\nПароль: " <<
				Encode(x.password )<< //.replace(0, x.password.size(),"********") << 
				"\nУровень допуска : " << x.status << "\n";
			i++;
		}
		int a;
		cout << "\n\nВведите действие: \n" << endl;
		cout << "\t1) Изменить Логин" << 
			"\n\t2) Изменить пароль" << 
			"\n\t3) Изменить уровень" << 
			"\n\t4) Удалить пользователя" <<
			"\n\t5) Добавить пользователя: " <<
			"\n\t6) Посмотреть пароли" << 
			"\n\t7) Сохранить и Выйти" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			if (usr_chk >= 3) {
				system("cls");
				string j;
				cout << "Введите номер Логина" << endl;
				cin >> j;
				if (isdigit(j[0])) {
					int z = stoi(j) - 1;
					if (z <= (signIn.size())) {
						cout << "Введите новый логин: ";
						cin >> signIn[z].login;
					}
					else {
						cout << "Такого пользователя нет!" << endl;
						system("pause");
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
		case 2:
		{
			if (usr_chk >= 3) {
				system("cls");
				string j;
				cout << "Введите номер Логина" << endl;
				cin >> j;
				if (isdigit(j[0])) {
					int z = stoi(j) - 1;
					if (z <= (signIn.size())) {
						cout << "Введите новый пароль: ";
						cin >> signIn[z].password;
					}
					else {
						cout << "Такого пользователя нет!" << endl;
						system("pause");
					}
				}
				else {
					cout << "Месье, вы дэбил, давайте по-новой." << endl;
					system("pause");
				}
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
				system("cls");
				string j;
				cout << "Введите номер Логина" << endl;
				cin >> j;
				if (isdigit(j[0])) {
					int z = stoi(j) - 1;
					if (z <= (signIn.size())) {
						while (true) {
							int lvl = 0;
							cout << "Введите новый уровень(Наименьшее значение: 1): ";
							cin >> lvl;
							if (lvl > 0) {
								signIn[z].status = lvl;
								break;
							}
							else {
								cout << "Wrong level!" << endl;
								system("pause");
							}
						}
					}
					else {
						cout << "Такого пользователя нет!" << endl;
						system("pause");
					}
				}
				else {
					cout << "Месье, вы дэбил, давайте по-новой." << endl;
					system("pause");
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
				string j;
				cout << "Введите номер Логина" << endl;
				cin >> j;
				if (isdigit(j[0])) {
					int z = stoi(j) - 1;
					if (z <= (signIn.size())) {
						signIn.erase(signIn.begin() + z - 1);
					}
					else {
						cout << "Такого пользователя нет!" << endl;
						system("pause");
					}
				}
				else {
					cout << "Месье, вы дэбил, давайте по-новой." << endl;
					system("pause");
				}
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
				string stat = "1";
				cout << "Введите новый логин: ";
				cin >> user.login;
				cout << "Введите новый пароль: ";
				cin >> user.password;

				while (true) {
					cout << "Введите новый уровень(Наименьшее значение: 1): ";
					cin >> stat;
					if (isdigit(stat[0])) {
						if (stoi(stat) <= usr_chk) {
							user.status = stoi(stat);
							break;
						}
						else {
							cout << "Wrong level!" << endl;
							system("pause");
						}
					}
					else {
						cout << "Месье, вы дэбил, давайте по-новой." << endl;
						system("pause");
						break;
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
				lgn << x.login << "\n" << Encode(x.password) << "\n" << x.status << "\n*\n";
			}

		}
	}
	lgn.close();
}