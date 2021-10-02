#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Order_Header.h"

using namespace std;

Order orderAdd(vector<Order>& vect);

void orderPrintAll(vector<Order>& order_list);

Order FindOrder(vector<Order>& order_list);

void printOrder(Order& order);

Order Edit_Order(Order& order);

Order deletOreder(Order& order);

vector<Order> saveOrder(vector<Order>& order_list, Order& order);

vector<Order> load_order();

int main() {
    system("chcp 1251"); 
    int a;
    vector<Order> orders;
    bool key = true;
    while (key) {
        system("cls");

        cout << "Заказы:\n" <<
            "\t1) Добавить заказ.\n" <<
            "\t2) Показать заказы.\n" <<
            "\t3) Найти заказ.\n" <<
            "\t4) Редактировать заказ\n" <<
            "\t5) Удалить заказ.\n" <<
            "\t6) Выгрузить заказы\n" <<
            "\t7) Выход\n";

        cin >> a;

        switch (a) {
        case 1: {
            orders.push_back(orderAdd(orders));
            break;
        }
        case 2: {
            orderPrintAll(orders);
            break;
        }
        case 3: {
            Order order = FindOrder(orders);
            printOrder(order);
            break;
        }

        case 4: {
            Order order = FindOrder(orders);
            order  = Edit_Order(order);
            saveOrder(orders, order);
            break;
        }

        case 5: {
            Order order = FindOrder(orders);
            order = deletOreder(order);
            saveOrder(orders, order);
            break;
        }
        case 6: {
            orders = load_order();
            break;
        }

        case 7: {
            key = false;
            break;
        }

        default: {
            cout << "Месье, вы дэбил, давайте по-новой." << endl;
            return 0;
        }
        };
    }
}