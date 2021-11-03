#include "Order.h"
using namespace std;


void Edit_Users(vector<Users>& signIn, int& usr_chk) {
	bool key = true;
	while (key) {
		int i = 1;
		system("cls");
		cout << "Âñå Ïîëüçîâàòåëè: " << endl;
		for (Users x : signIn) {
			string psw = "";
			for (int i = 0; i < x.password.size(); i++) {
				psw += "*";
			}
			cout << i << ")\nËîãèí: " << x.login << "\nÏàðîëü: " << psw << "\nÓðîâåíü äîïóñêà: " << x.status << "\n";
			i++;
		}
		int a;
		cout << "\n\nÂâåäèòå äåéñòâèå: \n" << endl;
		cout << "\t1) Èçìåíèòü Ëîãèí" << "\n\t2) Èçìåíèòü ïàðîëü" << "\n\t3) Èçìåíèòü óðîâåíü" << "\n\t4) Óäàëèòü ïîëüçîâàòåëÿ" << "\n\t5) Äîáàâèòü ïîëüçîâàòåëÿ: " << "\n\t6) Ïîñìîòðåòü ïàðîëè" << "\n\t7) Ñîõðàíèòü è Âûéòè" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
		{
			if (usr_chk >= 3) {
				system("cls");
				int j;
				cout << "Ââåäèòå íîìåð Ëîãèíà" << endl;
				cin >> j;
				j--;
				if (j <= (signIn.size())) {
					cout << "Ââåäèòå íîâûé ëîãèí: ";
					cin >> signIn[j].login;
				}
				else {
					cout << "Òàêîãî ïîëüçîâàòåëÿ íåò!" << endl;
					system("pause");
				}
				break;
			}
			else {
				cout << "Ó âàñ íåò äîñòóïà" << endl;
				system("pause");
				break;
			}
		}
		case 2:
		{
			if (usr_chk >= 3) {
				system("cls");
				int j;
				cout << "Ââåäèòå íîìåð Ëîãèíà" << endl;
				cin >> j;
				j--;
				if (j <= (signIn.size())) {
					cout << "Ââåäèòå íîâûé ïàðîëü: ";
					cin >> signIn[j].password;
				}
				else {
					cout << "Òàêîãî ïîëüçîâàòåëÿ íåò!" << endl;
					system("pause");
				}
				break;
			}
			else {
				cout << "Ó âàñ íåò äîñòóïà" << endl;
				system("pause");
				break;
			}
		}
		case 3:
		{
			if (usr_chk >= 3) {
				system("cls");
				int j;
				cout << "Ââåäèòå íîìåð Ëîãèíà" << endl;
				cin >> j;
				j--;
				if (j <= (signIn.size())) {
					while (true) {
						int lvl = 0;
						cout << "Ââåäèòå íîâûé óðîâåíü(Íàèìåíüøåå çíà÷åíèå: 1): ";
						cin >> lvl;
						if (lvl > 0) {
							signIn[j].status = lvl;
							break;
						}
						else {
							cout << "Wrong level!" << endl;
							system("pause");
						}
					}
				}
				else {
					cout << "Òàêîãî ïîëüçîâàòåëÿ íåò!" << endl;
					system("pause");
				}
				break;
			}
			else {
				cout << "Ó âàñ íåò äîñòóïà" << endl;
				system("pause");
				break;
			}
		}
		case 4:
		{
			if (usr_chk >= 3) {
				system("cls");
				int j;
				cout << "Ââåäèòå íîìåð Ëîãèíà" << endl;
				cin >> j;
				j--;
				if (j <= (signIn.size())) {
					signIn.erase(signIn.begin() + j - 1);
				}
				else {
					cout << "Òàêîãî ïîëüçîâàòåëÿ íåò!" << endl;
					system("pause");
				}
				break;
			}
			else {
				cout << "Ó âàñ íåò äîñòóïà" << endl;
				system("pause");
				break;
			}
		}
		case 5: {
			if (usr_chk >= 2) {
				system("cls");
				Users user;
				int stat = 1;
				cout << "Ââåäèòå íîâûé ëîãèí: ";
				cin >> user.login;
				cout << "Ââåäèòå íîâûé ïàðîëü: ";
				cin >> user.password;

				while (true) {
					cout << "Ââåäèòå íîâûé óðîâåíü(Íàèìåíüøåå çíà÷åíèå: 1): ";
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
				cout << "Ó âàñ íåò äîñòóïà" << endl;
				system("pause");
				break;
			}
		}
		case 6: {
			if (usr_chk >= 3) {
				system("cls");
				int j;
				cout << "Ââåäèòå íîìåð Ëîãèíà" << endl;
				cin >> j;
				j--;
				cout << "\n Ëîãèí: " << signIn[j].login << "\n Ïàðîëü: " << signIn[j].password << endl;
				system("pause");
				break;
			}
			else {
				cout << "Ó âàñ íåò äîñòóïà" << endl;
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