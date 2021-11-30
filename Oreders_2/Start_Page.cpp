
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
		cout << "������� �����\n�����: 1\n�����������: 2\n�����: 3" << endl;
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
			cout << "�����, �� �����, ������� ��-�����." << endl;
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
		cout << "\n\n������� ��������: \n" << 
		    "\t1) �������� �����" <<
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
				if (usrService.Del_User(usr))cout << "������������ ������." << endl;
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
			cout << "�����, �� �����, ������� ��-�����." << endl;
			break;
		}
	}
}