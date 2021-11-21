#include "Order.h"

using namespace std;

string base64_encode(string const& s, bool url);
int isInt();

using namespace std;

class OrderRepository
{
public:
	int FindOrder() {
		system("cls");
		cout << "Enter a order id:" << endl;
		int id = isInt();
		if (id <= orders.size()) {
			for (Order order : orders) {
				if (order.id == id && order.delete_status == 0 && order.Username == Username) {
					return (id - 1);
				}
			}
		}
		else throw exception("Месье, вы дэбил");
	}

	void filling() {
		vector<Order> orderList;
		fstream in;
		in.open("data.dat");
		if (in.is_open())
		{
			while (!in.eof()) {
				Order order;
				string data;
				int val;
				bool flag = true;
				getline(in, data);
				val = atoi(data.c_str()); 
				
				getline(in, data);
				order.Username = data;
				getline(in, data);
				order.description = data;
				getline(in, data);
				order.status = data;
				getline(in, data);
				order.price = atoi(data.c_str());
				getline(in, data);
				order.delete_status = atoi(data.c_str());
				getline(in, data);
				for (Order ord : orders) {
					if (ord.id != val) {
						order.id = val;
					}
					else order.delete_status = true;
				}
				for (Order ord : orderList) {
					if (ord.id != val) {
						order.id = val;
					}
					else order.delete_status = true;
				}
				if (order.delete_status == false)orderList.push_back(order);

			}
			orders.pop_back();
			for (Order ord : orderList) {
				for (int i = 0; i < orders.size(); i++)

					orders.push_back(ord);

			}
			in.close();
		}
	}

	void saveOrder_list() { //сохранение всех заказов в файл
		fstream in;
		in.open("data.dat");
		if (in.is_open()) {
			for (Order order : orders) {
				in << order.id << "\n" << order.Username << "\n" << order.description << "\n" << order.status << "\n" << order.price << "\n" << order.delete_status << "\n*\n";
			}
		}
		else cout << "error: гребанный рот этого казино, блин" << endl;
		in.close();
	}

	vector<Order> getAll() {
		return orders;
	}

	bool newOrder() {
		Order order;
		system("cls");
		order.id = static_cast<int>(orders.size()) + 1;
		order.delete_status = false;
		order.Username = Username;
		cout << "Введите новое описание заказа: ";
		(cin >> order.description).get();
		cout << "Введите новый статус заказа: ";
		(cin >> order.status).get();
		cout << "Введите новую стоимость заказа: ";
		int val = isInt();
		if (val >= 0) {
			order.price = val;
			orders.push_back(order);
			return 0;
		}
		else {
			throw exception("Неверное значение стоимости");
		}
	}

	Order EditOrder(int& id) {
		system("cls");
		orders[id].Username = Username;
		cout << "Введите новое описание заказа: ";
		(cin >> orders[id].description).get();
		cout << "Введите новый статус заказа: ";
		(cin >> orders[id].status).get();
		cout << "Введите новую стоимость заказа: ";
		int val = isInt();
		if (val >= 0) {
			orders[id].price = val;
			return orders[id];
		}
		else {
			throw exception("Неверное значение стоимости");
		}
	}

	bool deleteOrder(int& id)
	{
		orders[id].delete_status = 1;
		return 0;
	}

	void printAll() {
		system("cls");
		for (Order order : orders) {
			if (order.delete_status == 0 && order.Username == Username) {
				cout << "id: " << order.id << "\nДобавил(а): " << order.Username << "\nDescription: " << order.description << "\nStatus: " << order.status << "\nPrice: " << order.price << endl;
			}
		}
		system("pause");
	}

	int sumOrders() {
		int sum = 0;
		for (Order order : orders) {
			if (order.Username == Username) {
				sum += order.price;
			}
		}
		return sum;
	}

	void printOrder(int& id) { //вывод определленного заказа
		system("cls");
		if (orders[id].delete_status == 0) {
			cout << "id: " << orders[id].id << "\nДобавил(а): " << orders[id].Username << "\nDescription: "
				<< orders[id].description << "\nStatus: " << orders[id].status << "\nPrice: " << orders[id].price << endl;
			system("pause");
		}
		else throw exception();
	}

	void setUser(string& Usrnm) {
		Username = Usrnm;
	}

	void setPassword(string& Pswrd) {
		Password = Pswrd;
	}

	string getUser() {
		return Username;
	}

private:
	string Username, Password;
	vector<Order> orders;
};

class UserRepository
{
public:
	void filling() {
		ifstream lgn("login.txt");
		string data;
		if (lgn.is_open()) {
			while (!lgn.eof())
			{
				Users user;
				getline(lgn, data, '\n');
				user.login = data;
				getline(lgn, data, '\n');
				user.password = data;
				getline(lgn, data, '\n');
				user.status = atoi(data.c_str());
				getline(lgn, data, '\n');
				Registered.push_back(user);
			}
			Registered.pop_back();
		}
		lgn.close();
	}

	vector<Users> getAll() {
		return Registered;
	}

	int FindUser() {
		system("cls");
		string j;
		cout << "Введите Логин пользователя, которого желаете изменить." << endl;
		cin >> j;
		for (int i = 0; i < Registered.size(); i++) {
			if (Registered[i].login == j) return i;
		}
		throw exception("User not found!");

	}

	string EditLogin(int& id) {
		system("cls");
		string login;
		cout << "Введите новый логин: ";
		cin >> login;
		Registered[id].login = login;
		return login;
	}

	string EditPswrd(const int& id, bool flag) {

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
					Registered[id].password = psw1;
				}
				return base64_encode(psw1, true);
				break;
			}
			else { cout << "\n\nПароли не совпадают. Повторите еще раз:" << endl; system("pause"); }
		}
	}

	int EditLvl(int& id) {
		system("cls");
		while (true) {
			cout << "Введите новый уровень от 1 до 3: ";
			int lvl = isInt();
			if (lvl > 0 && lvl < 4) {
				Registered[id].status = lvl;
				return lvl;
				break;
			}
			else {
				cout << "Wrong level!" << endl;
				system("pause");
			}
		}
	}

	void Registration() {
		system("cls");
		Users User;
		bool key = true;
		fstream lgn("login.txt", ios::app);
		while (key)
		{
			cout << "Введите логин: ";
			(cin >> User.login).get();
			if (Registered.size() == 0)key = false;
			else {
				for (Users U : Registered) {
					if (U.login == User.login) {
						cout << "\nТакой пользователь уже существует." << endl;
						key = true;

					}
					else {
						key = false;
					}
				}
			}
		}

		User.password = EditPswrd(0, false);
		if (User.login == "admin") {
			User.status = 3;
		}
		else User.status = 1;
		if (lgn.is_open()) {
			lgn << User.login << "\n" << User.password << "\n" << User.status << "\n*\n";
		}
		lgn.close();
		Registered.push_back(User);
	}

	bool Authorization(OrderRepository& ordRepo) {
		string Username, Password;
		cout << "Login:" << endl;
		cin >> Username;
		cout << "Password:" << endl;
		cin >> Password;
		Password = base64_encode(Password, true);
		ordRepo.setUser(Username);
		ordRepo.setPassword(Password);
		for (int i = 0; i < Registered.size(); i++) {
			if (Registered[i].login == Username && Registered[i].password == Password) {
				return true;
			}
		}
		return false;
	}

	void Save_Users() {
		fstream lgn("login.txt");
		if (lgn.is_open()) {
			for (Users x : Registered) {
				if (x.status != 0) {
					lgn << x.login << "\n" << x.password << "\n" << x.status << "\n*\n";
				}

			}
		}
		lgn.close();
	}

	bool Del_User(int& id) {
		Registered.erase(Registered.begin() + id);
		return true;
	}

	int clearanceLevel(string& Username) {
		for (int i = 0; i < Registered.size(); i++) {
			if (Registered[i].login == Username) {
				return Registered[i].status;
			}
		}
	}

private:
	vector<Users> Registered;
};

