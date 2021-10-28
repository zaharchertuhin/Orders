#include "Order.h"

using namespace std;

void orderPrintAll(vector<Order>& order_list, string& Username) { //вывод всех заказов
	system("cls");

	for (Order order : order_list) {
		if (order.delete_status == 0 && order.Username == Username) {
			cout << "id: " << order.id << "\nАвтор: " << order.Username << "\nDescription: " << order.description << "\nStatus: " << order.status << "\nPrice: " << order.price << endl;
		}
	}
	system("pause");
}



Order FindOrder(vector<Order>& order_list, string& Username) { //поиск заказа
	system("cls");
	int id;
	cout << "Enter a order id:" << endl;
	cin >> id;
	if (id <= order_list.size()) {
		for (Order order : order_list) {
			if (order.id == id) {
				if (order.delete_status == 0 && order.Username == Username) {
					return order;
					break;
				}
			}
		}
	}
	Order ordrer;
	return ordrer;
}

int sumOrders(vector<Order>& order_list, string& Username) {
	int sum = 0;
	for (Order order : order_list) {
		if (order.Username == Username) {
			sum += order.price;
		}
	}
	return sum;
}

void printOrder(Order& order) { //вывод определленного заказа
	system("cls");
	if (order.delete_status == 0) {
		cout << "id: " << order.id << "\nАвтор: " << order.Username << "\nDescription: " << order.description << "\nStatus: " << order.status << "\nPrice: " << order.price << endl;
	}
	else cout << "Order not found" << endl;
	system("pause");
}