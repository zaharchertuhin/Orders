
#include "Orders.cpp"



int FindUser(UserRepository& usrRepo) {
	system("cls");
	string j;
	cout << "Введите Логин пользователя, которого желаете изменить." << endl;
	cin >> j;
	for (int i = 0; i < usrRepo.getAll().size(); i++) {
		if (usrRepo.getAll()[i].getLogin() == j) return i;
	}
	throw exception("User not found!");

}

string EditLogin(UserRepository& usrRepo , int& id) {
	system("cls");
	string login;
	cout << "Введите новый логин: ";
	cin >> login;
	usrRepo.getAll()[id].setLogin(login);
	return login;
}

string EditPswrd(UserRepository& usrRepo , const int& id, bool flag) {

	while (true)
	{
		system("cls");
		string psw1, psw2;
		cout << "Введите новый пароль: ";
		cin >> psw1;
		cout << "\n\nПовторите новый пароль: ";
		cin >> psw2;
		if (psw1 == psw2) {
			if (flag) {
				usrRepo.getAll()[id].setPassword(psw1);
			}
			return base64_encode(psw1, true);
			break;
		}
		else { cout << "\n\nПароли не совпадают. Повторите еще раз:" << endl; system("pause"); }
	}
}

int EditLvl(UserRepository& usrRepo , int& id) {
	system("cls");
	while (true) {
		cout << "Введите новый уровень от 1 до 3: ";
		int lvl = isInt();
		if (lvl > 0 && lvl < 4) {
			usrRepo.getAll()[id].setStatus(lvl);
			return lvl;
			break;
		}
		else {
			cout << "Wrong level!" << endl;
			system("pause");
		}
	}
}

bool Del_User(UserRepository& usrRepo , int& id) {
	usrRepo.getAll().erase(usrRepo.getAll().begin() + id);
	return true;
}

int clearanceLevel(UserRepository& usrRepo , string& Username) {
	for (int i = 0; i < usrRepo.getAll().size(); i++) {
		if (usrRepo.getAll()[i].getLogin() == Username) {
			return usrRepo.getAll()[i].getStatus();
		}
	}
	return 1;
}