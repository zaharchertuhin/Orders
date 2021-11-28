
#include <string>
#include "Users.cpp"
using namespace std;

bool StartPage(UserRepository& usrRepo) {
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
			bool val = usrRepo.Authorization();
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
	return false;
}

void Edit_Users(UserRepository& usrRepo) {
	bool key = true;
	while (key) {
		int i = 1;
		system("cls");
		cout << "��� ������������: " << endl;
		for (Users x : usrRepo.getAll()) {
			cout << i << ") �����: " << x.getLogin() << "\n������: ";
			for (int i = 0; i < x.getPassword().size(); i++) { cout << "*"; }
			/*cout << x.password.replace(x.password.begin(), x.password.end(), " * ");*/
			cout << "\n������� ������� : " << x.getStatus() << "\n\n";
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
				int id = FindUser(usrRepo);
				EditLogin(usrRepo , id);
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
				int id = FindUser(usrRepo);
				EditPswrd(usrRepo, id, true);
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
				int id = FindUser(usrRepo);
				EditLvl(usrRepo , id);
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
				int id = FindUser(usrRepo);
				system("cls");
				if (Del_User(usrRepo , id))cout << "������������ ������." << endl;
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