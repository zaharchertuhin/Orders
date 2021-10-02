#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include "Order_Header.h"

using namespace std;

void orderPrintAll(vector<Order>& order_list) {
    system("cls");

    for (Order order : order_list) {
       
        if (order.delete_status == 0) {
            cout << "id: " << order.id << "\nDescription: " << order.description << "\nStatus: " << order.status << endl;
        }
    }
    
    system("pause");
}

Order FindOrder(vector<Order>& order_list) {
    system("cls");
    int id;
    cout << "Enter a order id:" << endl;
    cin >> id;
    for (Order order : order_list) {
        if (order.id == id) {
            if (order.delete_status == 0) {
                return order;
                break;
            }
        }
    }
    Order ordrer;
    return ordrer;
}

void printOrder(Order& order) {
    system("cls");
    cout << "id: " << order.id << "\nDescription: " << order.description << "\nStatus: " << order.status << endl;
    system("pause");
}

