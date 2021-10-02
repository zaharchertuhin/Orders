#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Order_Header.h"

using namespace std;

vector<Order> load_order() {
    vector<Order> order_list;
    system("cls");
    fstream in;
    string value_of_orders, data;
    int vectsize = 0;
    in.open("data.dat");
    if (in.is_open())
    {
        Order order;

        //количество заказов в файле
        while (!in.eof()) { 
            getline(in, value_of_orders, '*');
            vectsize++;
        }
        vectsize--;

        //считывание данных из файла
        for (int i = 0; i < vectsize; i++) {
            getline(in, data, '\n');
            order.id = i+1;
            cout << order.id << endl;
            getline(in, data, '\n');
            order.description = data;
            cout << order.description << endl;
            getline(in, data, '\n');
            order.status = data;
            cout << order.status << endl;
            getline(in, data, '\n');
            if (data.find("True"))order.delete_status = 1;
            else order.delete_status = 0;
            cout << order.delete_status << endl;

            //запись в вектор
            order_list.push_back(order);


        }
        system("pause");
        return order_list;
    }
}
