#include "Order.h"

using namespace std;

string base64_encode(string const& s, bool url);
int isInt();

class OrderRepository
{
public:
	bool saveOrder(Order& ord) {
		orders.push_back(ord);
		return true;
	}

	bool saveOrder(Order& ord, int& id) {
		orders[id] = ord;
		return true;
	}

	bool filling() {
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
				order.setUsername(data);
				getline(in, data);
				order.setDescription(data);
				getline(in, data);
				order.setStatus(data);
				getline(in, data);
				int v = atoi(data.c_str());
				order.setPrice(v);
				getline(in, data);

				order.setDelStatus(atoi(data.c_str()));
				getline(in, data);
				for (Order ord : orders) {
					if (ord.getId() != val) {
						order.setId(val);
					}
					else order.setDelStatus(true);
				}
				for (Order ord : orders) {
					if (ord.getId() != val) {
						order.setId(val);
					}
					else order.setDelStatus(true);
				}
				if (order.getDelStatus() == false)orders.push_back(order);

			}
			orders.pop_back();
			for (Order ord : orders) {
				for (int i = 0; i < orders.size(); i++)

					orders.push_back(ord);

			}
			in.close();
			return true;
		}
		return false;
	}

	bool saveOrder_list() { //сохранение всех заказов в файл
		fstream in;
		in.open("data.dat");
		if (in.is_open()) {
			for (Order order : orders) {
				in << order.getId() << "\n" << order.getUsername() << "\n" << order.getDescription() 
					<< "\n" << order.getStatus() << "\n" << order.getPrice() << "\n" << order.getDelStatus() << "\n*\n";
			}
		}
		else {
			cout << "error: гребанный рот этого казино, блин" << endl;
			return false;
		}
		in.close();
		return true;
	}

	bool deleteById(int& id) {
		orders[id].setDelStatus(1);
		return true;
	}

	vector<Order> getAll() {
		return orders;
	}

private:
	vector<Order> orders ;
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
				user.setLogin(data);
				getline(lgn, data, '\n');
				user.setPassword(data);
				getline(lgn, data, '\n');
				int v = atoi(data.c_str());
				user.setStatus(v);
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

	void Registration() {
		system("cls");
		Users User;
		string line;
		bool key = true;
		fstream lgn("login.txt", ios::app);
		while (key)
		{
			
			cout << "Введите логин: ";
			(cin >> line).get();
			User.setLogin(line);
			if (Registered.size() == 0)key = false;
			else {
				for (Users U : Registered) {
					if (U.getLogin() == User.getLogin()) {
						cout << "\nТакой пользователь уже существует." << endl;
						key = true;

					}
					else {
						key = false;
					}
				}
			}
		}
		while (true)
		{
			system("cls");
			string psw1, psw2;
			cout << "Введите новый пароль: ";
			cin >> psw1;
			cout << "\n\nПовторите новый пароль: ";
			cin >> psw2;
			if (psw1 == psw2) {
				
					psw1 = base64_encode(psw1, true);
					line = psw1;
				
			}
			else { cout << "\n\nПароли не совпадают. Повторите еще раз:" << endl; system("pause"); }
		}
		User.setPassword(line);
		if (User.getLogin() == "admin") {
			User.setStatus(3);
		}
		else User.setStatus(1);
		if (lgn.is_open()) {
			lgn << User.getLogin() << "\n" << User.getPassword() << "\n" << User.getStatus() << "\n*\n";
		}
		lgn.close();
		Registered.push_back(User);
	}

	bool Authorization() {
		string  Password;
		cout << "Login:" << endl;
		cin >> Username;
		cout << "Password:" << endl;
		cin >> Password;
		Password = base64_encode(Password, true);
		for (int i = 0; i < Registered.size(); i++) {
			if (Registered[i].getLogin() == Username && Registered[i].getPassword() == Password) {
				return true;
			}
		}
		return false;
	}

	void Save_Users() {
		fstream lgn("login.txt");
		if (lgn.is_open()) {
			for (Users x : Registered) {
				if (x.getStatus() != 0) {
					lgn << x.getLogin() << "\n" << x.getPassword() << "\n" << x.getStatus() << "\n*\n";
				}

			}
		}
		lgn.close();
	}

	string Usrnme() {
		return Username;
	}

private:
	string Username;
	vector<Users> Registered;
};
