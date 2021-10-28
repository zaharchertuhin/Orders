#include "Order.h"

using namespace std;

void saveOrder(Order& order);

Order orderAdd(vector<Order>& order_list, string& Username) { // добавление заказа
    Order order;
    system("cls");
    string val;
    order.id = static_cast<int>(order_list.size()) + 1;
    order.delete_status = false;
    order.Username = Username;
    cout << "Введите описание заказа: ";
    (cin >> order.description).get();
    cout << "Введите статус заказа: ";
    (cin >> order.status).get();
    cout << "Введите стоимость заказа: ";
    cin >> val;
	if (isdigit(val[0])) {
		order.price = stoi(val); 
        saveOrder(order);
		return order;
	}
    else {
        cout << "Заказ заполнен неправильно!" << endl;
        system("pause");
        Order ordrer;
        return ordrer;
    }

}

Order Edit_Order(Order& order, string& Username) { // изменение заказа
    system("cls");
    string val;
    order.Username = Username;
    cout << "Введите описание заказа: ";
    (cin >> order.description).get();
    cout << "Введите статус заказа: ";
    (cin >> order.status).get();
    cout << "Введите стоимость заказа: ";
    cin >> val;
    if (isdigit(val[0])) {
        order.price = stoi(val);
        saveOrder(order);
        system("pause");
        return order;
    }
    else {
        cout << "Заказ заполнен неправильно!" << endl;
        system("pause");
        Order ordrer;
        return ordrer;
    }
}

Order delete_Order(Order& order) { //удаление заказа
    system("cls");
    order.delete_status = 1;
    return order;
}

void saveOrders(vector<Order>& order_list, Order& order) { //сохранение заказа в вектор
    system("cls");
    uint32_t i = order.id - 1;
    order_list[i] = order;
}

void saveOrder(Order& order) { //сохранение заказа в файл при редактировании
    fstream in;
    in.open("data.dat", ios::app);
    if (in.is_open()) {
        in << order.id << "\n" << order.Username << "\n" << order.description << "\n" << order.status << "\n" << order.price << "\n" << order.delete_status << "\n*\n";
    }
    in.close();
}