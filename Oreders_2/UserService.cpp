#include "User.h"
#include "UserRepository.cpp"

string base64_encode(string const& s, bool url);

class UserService {
private:
	User last_user;
	UserRepository user_repo; // а тут ты решил передумать: user_repo;

public:

	bool Registration() {
		system("cls");
		User user;
		string line;
		bool key = true;
		fstream lgn("login.txt", ios::app);
		while (key)
		{
			cout << "Введите логин: ";
			(cin >> line).get();
			user.setLogin(line);
			if (user_repo.getAll().size() == 0)key = false;
			else {
				for (User U : user_repo.getAll()) {
					if (U.getLogin() == user.getLogin()) {
						cout << "\nТакой пользователь уже существует." << endl;
						key = true;

					}
					else {
						break;
					}
				}
			}
			string psw1, psw2;
			cout << "\nВведите новый пароль: ";
			cin >> psw1;
			cout << "\nПовторите новый пароль: ";
			cin >> psw2;
			if (psw1 == psw2) {

				psw1 = base64_encode(psw1, true);
				user.setPassword(psw1);
				key = false;

			}
			else { cout << "\n\nПароли не совпадают. Повторите еще раз:" << endl; system("pause"); }
		}

		if (user.getLogin() == "admin") {
			user.setStatus(3);
		} else user.setStatus(1);

		if (lgn.is_open()) {
			lgn << user.getLogin() << "\n" << user.getPassword() << "\n" << user.getStatus() << "\n*\n";
		}

		lgn.close();
		user_repo.saveNewUser(user);
		user_repo.saveUsers();
		return true;
	}

	bool Authorization(string& username, string& password) {
		password = base64_encode(password, true);
		for (int i = 0; i < user_repo.getAll().size(); i++) {
			if (user_repo.get(username).getLogin() == username && user_repo.get(username).getPassword() == password) {
				last_user = user_repo.get(username);
				return true;
			}
		}
		return false;
	}

	User FindUser(string& j) {
		User usr = user_repo.get(j);
		if (usr.getLogin() != "") {
			return usr;
		}
		else throw exception("User not found!");

	}

	bool EditLogin(User& usr, string& login) {
		system("cls");
		string lg = usr.getLogin();
		usr.setLogin(login);
		user_repo.saveUser(usr, lg);
		user_repo.saveUsers();
		return 0;
	}

	bool EditPswrd(User& usr, string& psw1, string& psw2) {
		string lg = usr.getLogin();
		while (true)
		{
			system("cls");
			if (psw1 == psw2) {
				psw1 = base64_encode(psw1, true);
				usr.setPassword(psw1);
				user_repo.saveUser(usr, lg);
				user_repo.saveUsers();
				return 0;
				break;
			}
			else {throw exception("Пароли не совпадают.Повторите еще раз : "); system("pause"); }
		}
	}

	bool EditLvl(User& usr, int lvl) {
		system("cls");
		string lg = usr.getLogin();
		while (true) {
			if (lvl > 0 && lvl < 4) {
				usr.setStatus(lvl);
				user_repo.saveUser(usr, lg);
				user_repo.saveUsers();
				return 0;
				break;
			}
			else {
				throw exception("Wrong level!");
				system("pause");
			}
		}
	}

	bool Del_User(User& usr) {
		user_repo.deleteUser(usr);
		user_repo.saveUsers();
		return true;
	}


	void Filling() {
		user_repo.filling();
	}

	void PrintUsers() {
		int i = 1;
		system("cls");
		cout << "Все Пользователи: " << endl;
		for (User x : user_repo.getAll()) {
			cout << i << ") Логин: " << x.getLogin() << "\nПароль: ";
			for (int i = 0; i < x.getPassword().size(); i++) { cout << "*"; }
			/*cout << x.password.replace(x.password.begin(), x.password.end(), " * ");*/
			cout << "\nУровень допуска : " << x.getStatus() << "\n\n";
			i++;
		}
	}

	int GetLevel() {
		return last_user.getStatus();
	}

	bool SaveUsers() {
		user_repo.saveUsers();
		return true;
	}

	/**
	* Вынеси private в начало лучше
	* У тебя названия методов то с большой, то с маленькой буквы, определись уже
	* если интересы конвенции именно плюса, то вот: https://google.github.io/styleguide/cppguide.html#Naming
	*/
};