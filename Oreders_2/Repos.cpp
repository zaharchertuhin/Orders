#include "Order.h"
#include "User.h" 

using namespace std;

string base64_encode(string const& s, bool url);
int isInt();

class OrderRepository
{
public:
	bool saveOrder(Order& ord) {
		if (ord.getId() <= (orders.size() + 1)) {
			int id = ord.getId() - 1;
			orders[id] = ord;
			return true;
		}
		else {
			orders.push_back(ord);
			return true;
		}
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

	Order get(int& id) {
		for (auto o : orders) {
			if (o.getId() == id) {
				return o;
			}
		}
		return Order();
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
	bool filling() {
		ifstream lgn("login.txt");
		string data;
		if (lgn.is_open()) {
			while (!lgn.eof())
			{
				User user;
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
		return 0;
	}

	User get(string& login) {
		for (auto o : Registered) {
			if (o.getLogin() == login) {
				return o;
			}
		}
		return User();
	}

	vector<User> getAll() {
		return Registered;
	}

	bool SaveNewUser(User& usr) {
		Registered.push_back(usr);
		return 0;
	}

	bool SaveUser(User&  usr, string& lg) {
		for (int i = 0; i < Registered.size(); i++) {
			if (Registered[i].getLogin() == lg) {
				Registered[i] = usr;
				return 0;
			}
		}
	}

	bool DeleteUser(User& usr) {
		for (auto o : Registered) {
			int i = 0;
			if (usr.getLogin() == o.getLogin()) {
				Registered.erase(Registered.begin() + i);
			}
			i++;
		}
		return 0;
	}

	bool Save_Users() {
		fstream lgn("login.txt");
		if (lgn.is_open()) {
			for (User x : Registered) {
				if (x.getStatus() != 0) {
					lgn << x.getLogin() << "\n" << x.getPassword() << "\n" << x.getStatus() << "\n*\n";
				}

			}
		}
		lgn.close();
		return 0;
	}

private:
	vector<User> Registered;
};
