#include "Order.h"

using namespace std;

string base64_encode(string const& s, bool url);
int isInt();

class OrderRepository
{
private:
	vector<Order> orders;

public:
	bool saveOrder(Order& ord) {
		if (ord.getId() <= (orders.size())) {
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
				order.setId(val);
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
				if (order.getDelStatus() == false)orders.push_back(order);

			}
			orders.pop_back();
			
			in.close();
			return true;
		}
		return false;
	}

	bool saveOrderList() { //сохранение всех заказов в файл
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
		id--;
		orders[id].setDelStatus(1);
		return true;
	}

	Order get(int& id) {
		for (auto o : orders) {
			if (o.getId() == id) {
				return o;
			}
		}
		throw exception("Order not found.");
		return Order();
	}

	vector<Order> getAll() {
		return orders;
	}
};