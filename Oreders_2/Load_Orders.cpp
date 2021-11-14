#include "Order.h"

using namespace std;

int isInt();

vector<Order> load_order() { //выгрузка заказов
	vector<Order> order_list;
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
	}
	return order_list;
}

Order pshBckOrdr(vector<Order>& order_list) {
	for (Order u : order_list) {
		u.id = static_cast<int>(order_list.size()) + 1;
		return u;
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
	else cout << "error: гребанный рот этого казино, блин" << endl;
	in.close();
}

void saveToFile(Order& order) { //сохранение заказа в файл при редактировании
	fstream in;
	in.open("data.dat");
	if (in.is_open()) {
		in << order.id << "\n" << order.Username << "\n" << order.description << "\n" << order.status << "\n" << order.price << "\n" << order.delete_status << "\n*\n";
	}
	in.close();
}

void saveToVector(vector<Order>& order_list, Order& order) { //сохранение заказа в вектор
	system("cls");
	uint32_t i = order.id - 1;
	order_list[i] = order;
}