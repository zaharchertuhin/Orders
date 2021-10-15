#include "Order_Header.h"

using namespace std;

void saveOrder(Order& order);

Order orderAdd(vector<Order>& order_list, string& Username) { // добавление заказа
    Order order;
    system("cls");

    order.id = order_list.size() + 1;
    order.delete_status = false;
    order.Username = Username;
    cout << "¬ведите описание заказа: ";
    cin >> order.description;
    cout << "¬ведите статус заказа: ";
    cin >> order.status;
    saveOrder(order);
    return order;
}

Order Edit_Order(Order& order, string& Username) { // изменение заказа
    system("cls");
    order.Username = Username;
    cout << "¬ведите описание заказа: ";
    cin >> order.description;
    cout << "¬ведите статус заказа: ";
    cin >> order.status;
    system("pause");
    return order;
}

Order delete_Order(Order& order) { //удаление заказа
    system("cls");
    order.delete_status = 1;
    return order;
}

void saveOrders(vector<Order>& order_list, Order& order) { //сохранение заказа в вектор
    system("cls");
    order_list[order.id - 1] = order;
}

void saveOrder(Order& order) { //сохранение заказа в файл при редактировании
    fstream in;
    in.open("data.dat", ios::app);
    if (in.is_open()) {
        in << order.id<< "\n" << order.Username << "\n" << order.description << "\n" << order.status << "\n" << order.delete_status << "\n*\n";
    }
}