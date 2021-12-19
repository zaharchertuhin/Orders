#include "UserService.cpp"

using namespace std;
string base64_encode(string const& s, bool url);
int isInt();

bool StartPage() {
	UserService usrService;
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
			try {
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
			catch (const std::exception& exp){
				cout << "\n" << exp.what() << endl;
				system("pause");

			}
		}
		case 2:
		{
			key = false;
			try
			{
				string line;
				cout << "Введите логин: ";
				(cin >> line).get();
				string psw1, psw2;
				cout << "\nВведите новый пароль: ";
				cin >> psw1;
				cout << "\nПовторите новый пароль: ";
				cin >> psw2;
				usrService.Registration(line, psw1, psw2);
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
