#include "Order.h"

using namespace std;

void saveToFile(Order& order);
Order Edit_Order(Order& order, string& Username, bool showOrd);
int isInt();

Order orderAdd(vector<Order>& order_list, string& Username) { // добавление заказа
	Order order;
	system("cls");
	order.id = static_cast<int>(order_list.size()) + 1;
	order.delete_status = false;
    order = Edit_Order(order, Username, false);
    return order;
}

Order Edit_Order(Order& order, string& Username, bool showOrd) { // изменение заказа
    system("cls");
	if (order.delete_status == true) {
        throw exception("Заказ удален");
	}
    if (showOrd) {
        cout << "id: " << order.id << "\nДобавил(а): " << order.Username << "\nDescription: " << order.description << "\nStatus: " << order.status << "\nPrice: " << order.price << "\n\n";
    }
	order.Username = Username;
    cout << "Введите новое описание заказа: ";
    (cin >> order.description).get();
    cout << "Введите новый статус заказа: ";
    (cin >> order.status).get();
    cout << "Введите новую стоимость заказа: ";
    int val = isInt();
	if (val >= 0) {
		order.price = val;
		saveToFile(order);
		return order;
	}
	else {
		throw exception("Неверное значение стоимости");
	}
}

Order delete_Order(Order& order) { //удаление заказа
    system("cls");
    order.delete_status = 1;
    return order;
}
