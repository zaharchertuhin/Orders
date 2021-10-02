#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Order_Header.h"

using namespace std;

Order orderAdd(vector<Order>& order_list) {
    Order order;
    system("cls");

    order.id = order_list.size() + 1;
    order.delete_status = false;
    cout << "¬ведите описание заказа: ";
    cin >> order.description;
    cout << "¬ведите статус заказа: ";
    cin >> order.status;
    return order;
}

Order Edit_Order(Order& order) {
    system("cls");
    cout << "¬ведите описание заказа: ";
    cin >> order.description;
    cout << "¬ведите статус заказа: ";
    cin >> order.status;
    system("pause");
    return order;
}

Order deletOreder(Order& order) {
    system("cls");
    order.delete_status = 1;
    return order;
}

vector<Order> saveOrder(vector<Order>& order_list, Order& order) {
    system("cls");
    order_list[order.id - 1].id = order.id;
    order_list[order.id - 1].description = order.description;
    order_list[order.id - 1].status = order.status;
    order_list[order.id - 1].delete_status = order.delete_status;
    return order_list;
}