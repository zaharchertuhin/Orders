#include "UserService.cpp"

using namespace std;
string base64_encode(string const& s, bool url);
int isInt();
UserService usrService;

string Find() {
	system("cls");
	string j;
	cout << "Введите Логин пользователя, которого желаете изменить: ";
	cin >> j;
	cout << "\n";
	return j;
}

int getLevel() {
	return usrService.GetLevel();
}

bool StartPage() {
	bool key = true; 
	usrService.Filling();
	while (key)
	{
		system("cls");
		cout << "Введите число\nВойти: 1\nРегистрация: 2\nВыход: 3" << endl;
		int a = isInt();
		switch (a) {
		case 1:
		{
			string username, password;
			system("cls");
			key = false;
			cout << "Login:"; 
			cin >> username;
			cout << "\nPassword:"; 
			cin >> password;
			bool val = usrService.Authorization(username, password);
			return val;
			break;
		}
		case 2:
		{
			key = false;
			usrService.Registration();
			
			break;
		}
		case 3: 
		{
			exit(0);
		}
		default: {
			cout << "Месье, вы дэбил, давайте по-новой." << endl;
			system("pause");
			break;
		}
		}
	}
	return false;
}

void Edit_Users() {
	bool key = true;
	while (key) {
		usrService.PrintUsers();
		cout << "\n\nВведите действие: \n" << 
		    "\t1) Изменить Логин" <<
			"\n\t2) Изменить пароль" <<
			"\n\t3) Изменить уровень" <<
			"\n\t4) Удалить пользователя" <<
			"\n\t5) Добавить пользователя " <<
			"\n\t6) Сохранить и Выйти" << endl;
		int a = isInt();
		switch (a)
		{
		case 1:
		{
			try
			{
				string u = Find();
				User usr = usrService.FindUser(u);
				string login;
				cout << "Введите новый логин: "; 
				cin >> login;
				usrService.EditLogin(usr, login);
			}
			catch (const std::exception& exp)
			{
				cout << "\n" << exp.what() << endl;
				system("pause");
			}
			break;
		}
		case 2:
		{
			try
			{
				string u = Find();
				User usr = usrService.FindUser(u);
				string psw1, psw2;
				cout << "Введите новый пароль: ";
				cin >> psw1;
				cout << "\n\nПовторите новый пароль: ";
				cin >> psw2;
				usrService.EditPswrd(usr, psw1, psw2);
			}
			catch (const std::exception& exp)
			{
				cout << "\n" << exp.what() << endl;
				system("pause");
			}
			break;
		}
		case 3:
		{
			try
			{
				string u = Find();
				User usr = usrService.FindUser(u);
				cout << "Введите новый уровень от 1 до 3: ";
				int lvl = isInt();
				usrService.EditLvl(usr, lvl);
			}
			catch (const std::exception& exp)
			{
				cout << "\n" << exp.what() << endl;
				system("pause");
			}
			break;
		}
		case 4:
		{
			try
			{
				string u = Find();
				User usr = usrService.FindUser(u);
				if (usrService.Del_User(usr))cout << "Пользователь удален." << endl;
				system("pause");
			}
			catch (const std::exception& exp)
			{
				cout << "\n" << exp.what() << endl;
				system("pause");
			}
			break;
		}
		case 5:
		{
			try
			{
				usrService.Registration();
			}
			catch (const std::exception& exp)
			{
				cout << "\n" << exp.what() << endl;
				system("pause");
			}
			break;
		}
		case 6:
		{
			key = false;
			usrService.SaveUsers();
			break;
		}
		default:
			cout << "Месье, вы дэбил, давайте по-новой." << endl;
			break;
		}
	}
}