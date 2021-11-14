#include "Order.h"

using namespace std;

int isInt();

void orderPrintAll(vector<Order>& order_list, string& Username) { //вывод всех заказов
	system("cls");

	for (Order order : order_list) {
		if (order.delete_status == 0 && order.Username == Username) {
			cout << "id: " << order.id << "\nДобавил(а): " << order.Username << "\nDescription: " << order.description << "\nStatus: " << order.status << "\nPrice: " << order.price << endl;
		}
	}
	system("pause");
}

Order FindOrder(vector<Order>& order_list, string& Username) { //поиск заказа
	system("cls");
	cout << "Enter a order id:" << endl;
	int id = isInt();
		if (id <= order_list.size()) {
			for (Order order : order_list) {
				if (order.id == id && order.delete_status == 0 && order.Username == Username) {
					return order;
					break;
				}
			}
		}
		else throw exception();
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
		cout << "id: " << order.id << "\nДобавил(а): " << order.Username << "\nDescription: " << order.description << "\nStatus: " << order.status << "\nPrice: " << order.price << endl;
	}
	else throw exception();
}