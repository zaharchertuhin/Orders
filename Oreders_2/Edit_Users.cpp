
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
		cout << "��� ������������: " << endl;
		for (Users x : signIn) {
			cout << i << ")\n�����: " << 
				x.login << "\n������: " <<
				Encode(x.password )<< //.replace(0, x.password.size(),"********") << 
				"\n������� ������� : " << x.status << "\n";
			i++;
		}
		int a;
		cout << "\n\n������� ��������: \n" << endl;
		cout << "\t1) �������� �����" << 
			"\n\t2) �������� ������" << 
			"\n\t3) �������� �������" << 
			"\n\t4) ������� ������������" <<
			"\n\t5) �������� ������������: " <<
			"\n\t6) ���������� ������" << 
			"\n\t7) ��������� � �����" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			if (usr_chk >= 3) {
				system("cls");
				string j;
				cout << "������� ����� ������" << endl;
				cin >> j;
				if (isdigit(j[0])) {
					int z = stoi(j) - 1;
					if (z <= (signIn.size())) {
						cout << "������� ����� �����: ";
						cin >> signIn[z].login;
					}
					else {
						cout << "������ ������������ ���!" << endl;
						system("pause");
					}
				}
				break;
			}
			else {
				cout << "� ��� ��� �������" << endl;
				system("pause");
				break;
			}
		}
		case 2:
		{
			if (usr_chk >= 3) {
				system("cls");
				string j;
				cout << "������� ����� ������" << endl;
				cin >> j;
				if (isdigit(j[0])) {
					int z = stoi(j) - 1;
					if (z <= (signIn.size())) {
						cout << "������� ����� ������: ";
						cin >> signIn[z].password;
					}
					else {
						cout << "������ ������������ ���!" << endl;
						system("pause");
					}
				}
				else {
					cout << "�����, �� �����, ������� ��-�����." << endl;
					system("pause");
				}
				break;
			}
			else {
				cout << "� ��� ��� �������" << endl;
				system("pause");
				break;
			}
		}
		case 3:
		{
			if (usr_chk >= 3) {
				system("cls");
				string j;
				cout << "������� ����� ������" << endl;
				cin >> j;
				if (isdigit(j[0])) {
					int z = stoi(j) - 1;
					if (z <= (signIn.size())) {
						while (true) {
							int lvl = 0;
							cout << "������� ����� �������(���������� ��������: 1): ";
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
						cout << "������ ������������ ���!" << endl;
						system("pause");
					}
				}
				else {
					cout << "�����, �� �����, ������� ��-�����." << endl;
					system("pause");
				}
				break;
			}
			else {
				cout << "� ��� ��� �������" << endl;
				system("pause");
				break;
			}
		}
		case 4:
		{
			if (usr_chk >= 3) {
				system("cls");
				string j;
				cout << "������� ����� ������" << endl;
				cin >> j;
				if (isdigit(j[0])) {
					int z = stoi(j) - 1;
					if (z <= (signIn.size())) {
						signIn.erase(signIn.begin() + z - 1);
					}
					else {
						cout << "������ ������������ ���!" << endl;
						system("pause");
					}
				}
				else {
					cout << "�����, �� �����, ������� ��-�����." << endl;
					system("pause");
				}
				break;
			}
			else {
				cout << "� ��� ��� �������" << endl;
				system("pause");
				break;
			}
		}
		case 5: {
			if (usr_chk >= 2) {
				system("cls");
				Users user;
				string stat = "1";
				cout << "������� ����� �����: ";
				cin >> user.login;
				cout << "������� ����� ������: ";
				cin >> user.password;

				while (true) {
					cout << "������� ����� �������(���������� ��������: 1): ";
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
						cout << "�����, �� �����, ������� ��-�����." << endl;
						system("pause");
						break;
					}

				}
				signIn.push_back(user);
				break;
			}
			else {
				cout << "� ��� ��� �������" << endl;
				system("pause");
				break;
			}
		}
		case 6: {
			if (usr_chk >= 3) {
				system("cls");
				int j;
				cout << "������� ����� ������" << endl;
				cin >> j;
				j--;
				cout << "\n �����: " << signIn[j].login << "\n ������: " << signIn[j].password << endl;
				system("pause");
				break;
			}
			else {
				cout << "� ��� ��� �������" << endl;
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

