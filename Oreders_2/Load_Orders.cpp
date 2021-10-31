#include "Order.h"

using namespace std;

vector<Order> load_order(vector<Order>& orders) { //âûãðóçêà çàêàçîâ
	vector<Order> order_list = orders;
	system("cls");
	fstream in;
	in.open("data.dat");
	if (in.is_open())
	{
		while (!in.eof()) {
			Order order;
			string data;

			bool flag = true;
			getline(in, data);
			if (orders.size() == 0) order.id = atoi(data.c_str());
			else {
				for (auto j : orders) {
					if (atoi(data.c_str()) == j.id) {

						flag = false;
						
						break;

					}
				}

			}
			if (flag) {
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
			}

		}
		order_list.pop_back();
		in.close();
		system("pause");
		return order_list;
	}
}

//void Delet_BD() {
//	fstream in;
//	in.open("data.dat");
//	if (in.is_open()) {
//
//	}
//}

void saveOrder_list(vector<Order>& order_list) { //ñîõðàíåíèå âñåõ çàêàçîâ â ôàéë
	fstream in;
	in.open("data.dat");
	if (in.is_open()) {
		for (Order order : order_list) {
			in << order.id << "\n" << order.Username << "\n" << order.description << "\n" << order.status << "\n" << order.price << "\n" << order.delete_status << "\n*\n";
		}
	}
	else cout << "error: fuck you ass" << endl;
}