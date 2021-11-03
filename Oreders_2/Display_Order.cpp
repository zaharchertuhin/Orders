#include "Order.h"

using namespace std;

void orderPrintAll(vector<Order>& order_list, string& Username) { //âûâîä âñåõ çàêàçîâ
	system("cls");

	for (Order order : order_list) {
		if (order.delete_status == 0 && order.Username == Username) {
			cout << "id: " << order.id << "\nÀâòîð: " << order.Username << "\nDescription: " << order.description << "\nStatus: " << order.status << "\nPrice: " << order.price << endl;
		}
	}
	system("pause");
}



Order FindOrder(vector<Order>& order_list, string& Username) { //ïîèñê çàêàçà
	system("cls");
	string id;
	cout << "Enter a order id:" << endl;
	cin >> id;
	if (isdigit(id[0])) {
		if (stoi(id) <= order_list.size()) {
			for (Order order : order_list) {
				if (order.id == stoi(id)) {
					if (order.delete_status == 0 && order.Username == Username) {
						return order;
						break;
					}
				}
			}
		}

	}

	else cout << "Order not found" << endl;
	system("pause");

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

void printOrder(Order& order) { //âûâîä îïðåäåëëåííîãî çàêàçà
	system("cls");
	if (order.delete_status == 0) {
		cout << "id: " << order.id << "\nÀâòîð: " << order.Username << "\nDescription: " << order.description << "\nStatus: " << order.status << "\nPrice: " << order.price << endl;
	}
	else cout << "Order not found" << endl;
	system("pause");
}