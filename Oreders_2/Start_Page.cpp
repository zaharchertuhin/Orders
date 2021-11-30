
#include "UserService.cpp"

using namespace std;
string base64_encode(string const& s, bool url);
UserService usrService;


bool StartPage() {
	bool key = true; 
	usrService.Fillind();
	while (key)
	{
		system("cls");
		cout << "Введите число\nВойти: 1\nРегистрация: 2\nВыход: 3" << endl;
		int a = isInt();
		switch (a) {
		case 1: {
			system("cls");
			key = false;
			bool val = usrService.Authorization();
			return val;
			break;
		}
		case 2:
		{
			key = false;
			usrService.Registration();
			break;
		}
		case 3: {
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
		usrService.printUsers();
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
				User usr = usrService.FindUser();
				usrService.EditLogin(usr);
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
				User usr = usrService.FindUser();
				usrService.EditPswrd(usr);
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
				User usr = usrService.FindUser();
				usrService.EditLvl(usr);
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
				system("cls");
				User usr = usrService.FindUser();
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
			break;
		}
		default:
			cout << "Месье, вы дэбил, давайте по-новой." << endl;
			break;
		}
	}
}