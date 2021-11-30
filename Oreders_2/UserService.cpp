#include "User.h"
#include "Repos.cpp"

string base64_encode(string const& s, bool url);

class UserService {
public:

	bool Registration() {
		system("cls");
		User user;
		string line;
		bool key = true;
		fstream lgn("login.txt", ios::app);
		while (key)
		{
			cout << "������� �����: ";
			(cin >> line).get();
			user.setLogin(line);
			/*if (usrRepo.getAll().size() == 0)key = false;
			else {
				for (User U : usrRepo.getAll()) {
					if (U.getLogin() == user.getLogin()) {
						cout << "\n����� ������������ ��� ����������." << endl;
						key = true;

					}
					else {
						break;
					}
				}
			}*/
			string psw1, psw2;
			cout << "\n������� ����� ������: ";
			cin >> psw1;
			cout << "\n��������� ����� ������: ";
			cin >> psw2;
			if (psw1 == psw2) {

				psw1 = base64_encode(psw1, true);
				user.setPassword(psw1);
				key = false;

			}
			else { cout << "\n\n������ �� ���������. ��������� ��� ���:" << endl; system("pause"); }
		}

		if (user.getLogin() == "admin") {
			user.setStatus(3);
		} else user.setStatus(1);

		if (lgn.is_open()) {
			lgn << user.getLogin() << "\n" << user.getPassword() << "\n" << user.getStatus() << "\n*\n";
		}

		lgn.close();
		usrRepo.SaveNewUser(user);
		return true;
	}

	bool Authorization() {
		/**
		* ����� ���� ������ ������������ ������ ������� � ����, ��������, 
		* ��� ��� ����� ���������, � � autorization(string login, string password)
		*/
		cout << "Login:" << endl; //����� ������� �� ���� ������
		cin >> Username;
		cout << "Password:" << endl; // ����������
		cin >> Password;

		Password = base64_encode(Password, true);
		for (int i = 0; i < usrRepo.getAll().size(); i++) {
			if (usrRepo.get(Username).getLogin() == Username && usrRepo.get(Username).getPassword() == Password) {
				return true;
			}
		}
		return false;
	}

	User FindUser() {
		/**
		* ��� �� �� �����, � ������� �������� ������ ������, � �������������� � ������ ��������
		*/
		system("cls");
		string j;
		cout << "������� ����� ������������, �������� ������� ��������." << endl;
		cin >> j;

		User usr = usrRepo.get(j);
		if (usr.getLogin() != "") {
			return usr;
		}
		else throw exception("User not found!");

	}

	bool EditLogin(User& usr) {
		system("cls");
		string lg = usr.getLogin();
		string login;
		cout << "������� ����� �����: "; //������ �� �����
		cin >> login;
		usr.setLogin(login);
		usrRepo.SaveUser(usr, lg);
		return 0;
	}

	bool EditPswrd(User& usr) {
		string lg = usr.getLogin();
		while (true)
		{
			system("cls");
			string psw1, psw2;
			cout << "������� ����� ������: ";
			cin >> psw1;
			cout << "\n\n��������� ����� ������: ";
			cin >> psw2;
			if (psw1 == psw2) {
				psw1 = base64_encode(psw1, true);
				usr.setPassword(psw1);
				usrRepo.SaveUser(usr, lg);
				return 0;
				break;
			}
			else {throw exception("������ �� ���������.��������� ��� ��� : "); system("pause"); }
		}
	}

	bool EditLvl(User& usr) {
		system("cls");
		string lg = usr.getLogin();
		while (true) {
			cout << "������� ����� ������� �� 1 �� 3: ";
			int lvl = isInt();
			if (lvl > 0 && lvl < 4) {
				usr.setStatus(lvl);
				usrRepo.SaveUser(usr, lg);
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
		/**
		* ���� � ������, ���� ��� ������ �����
		* � ��� � �� ����� ����� ���� lg
		*/
		string lg = usr.getLogin();
		usrRepo.DeleteUser(usr);
		return true;
	}

	bool clearanceLevel(string& Usrname) {
		for (int i = 0; i < usrRepo.getAll().size(); i++) {
			if (usrRepo.get(Usrname).getLogin() == Usrname) {
				return true;
			}
		}
		return 1;
	}

	void Fillind() {
		usrRepo.filling();
	}

	void printUsers() {
		int i = 1;
		system("cls");
		cout << "��� ������������: " << endl;
		for (User x : usrRepo.getAll()) {
			cout << i << ") �����: " << x.getLogin() << "\n������: ";
			for (int i = 0; i < x.getPassword().size(); i++) { cout << "*"; }
			/*cout << x.password.replace(x.password.begin(), x.password.end(), " * ");*/
			cout << "\n������� ������� : " << x.getStatus() << "\n\n";
			i++;
		}
	}

	/**
	* ������ private � ������ �����
	* � ���� �������� ������� �� � �������, �� � ��������� �����, ���������� ���
	* ���� �������� ��������� ������ �����, �� ���: https://google.github.io/styleguide/cppguide.html#Naming
	*/

private: 
	string Username; // ������� ������, �������, �������� ���������� � ��������� ����� �����
	string  Password;
	UserRepository usrRepo; // � ��� �� ����� ����������: user_repo;
};