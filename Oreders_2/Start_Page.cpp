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
		cout << "������� �����\n�����: 1\n�����������: 2\n�����: 3" << endl;
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
			cout << "�����, �� �����, ������� ��-�����." << endl;
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
		cout << "��� ������������: " << endl;
		for (Users x : usrRepo.getAll()) {
			cout << i << ") �����: " << x.login << "\n������: ";
			for (int i = 0; i < x.password.size(); i++) { cout << "*"; }
			/*cout << x.password.replace(x.password.begin(), x.password.end(), " * ");*/
			cout << "\n������� ������� : " << x.status << "\n\n";
			i++;
		}

		cout << "\n\n������� ��������: \n" << endl;
		cout << "\t1) �������� �����" <<
			"\n\t2) �������� ������" <<
			"\n\t3) �������� �������" <<
			"\n\t4) ������� ������������" <<
			"\n\t5) �������� ������������ " <<
			"\n\t6) ��������� � �����" << endl;
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
				if (usrRepo.Del_User(id))cout << "������������ ������." << endl;
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
			cout << "�����, �� �����, ������� ��-�����." << endl;
			break;
		}
	}
}