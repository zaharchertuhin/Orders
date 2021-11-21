#include "Order.h"
#include <string>
#include "Repos.cpp"
using namespace std;

string base64_encode(std::string const& s, bool url);
void Edit_Users(UserRepository& usrRepo);
int isInt();

bool StartPage(UserRepository& usrRepo, OrderRepository& ordRepo) {
	bool key = true;
	while (key)
	{
		system("cls");
		cout << "Введите число\nВойти: 1\nРегистрация: 2\nВыход: 3" << endl;
		int a = isInt();
		switch (a) {
		case 1: {
			system("cls");
			key = false;
			bool val = usrRepo.Authorization(ordRepo);
			return val;
			break;
		}
		case 2:
		{
			key = false;
			usrRepo.Registration();
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
}

void Edit_Users(UserRepository& usrRepo) {
	bool key = true;
	while (key) {
		int i = 1;
		system("cls");
		cout << "Все Пользователи: " << endl;
		for (Users x : usrRepo.getAll()) {
			cout << i << ") Логин: " << x.login << "\nПароль: ";
			for (int i = 0; i < x.password.size(); i++) { cout << "*"; }
			/*cout << x.password.replace(x.password.begin(), x.password.end(), " * ");*/
			cout << "\nУровень допуска : " << x.status << "\n\n";
			i++;
		}

		cout << "\n\nВведите действие: \n" << endl;
		cout << "\t1) Изменить Логин" <<
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
				int id = usrRepo.FindUser();
				usrRepo.EditLogin(id);
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
				int id = usrRepo.FindUser();
				usrRepo.EditPswrd(id, true);
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
				int id = usrRepo.FindUser();
				usrRepo.EditLvl(id);
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
				int id = usrRepo.FindUser();
				system("cls");
				if (usrRepo.Del_User(id))cout << "Пользователь удален." << endl;
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
				usrRepo.Registration();
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