#include "Order.h"

using namespace std;

vector<Order> load_order(vector<Order>& orders) { //выгрузка заказов
	vector<Order> order_list = orders;
	system("cls");
	fstream in;
	in.open("data.dat");
	if (in.is_open())
	{
		int n = 1;
		//количество заказов в файле
		while (!in.eof()) {
			Order order;
			string data;
			bool key = true;
			getline(in, data);
			if (orders.size() == 0) order.id = atoi(data.c_str());
			else {
				for (auto j : orders) {
					//order.id = orders.size() + n;
					if (atoi(data.c_str()) == j.id) {
						//order.id = orders.size() + n + 1;
						key = false;
						break;
					}

				}

			}if (key) {
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
				if (order.delete_status == false)order_list.push_back(order);
				n++;
			}
		}
		order_list.pop_back();
		in.close();
		system("pause");
		return order_list;
	}
}



void saveOrder_list(vector<Order>& order_list) { //сохранение всех заказов в файл
	fstream in;
	in.open("data.dat");
	if (in.is_open()) {
		for (Order order : order_list) {
			in << order.id << "\n" << order.Username << "\n" << order.description << "\n" << order.status << "\n" << order.price << "\n" << order.delete_status << "\n*\n";
		}
	}
	else cout << "error: fuck you ass" << endl;
}