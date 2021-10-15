#include "Order_Header.h"

using namespace std;

vector<Order> load_order() { //выгрузка заказов
    vector<Order> order_list;
    system("cls");
    fstream in;
    in.open("data.dat");
    if (in.is_open())
    {
        //количество заказов в файле
        while (!in.eof()) { 
            Order order;
            string data;
            getline(in, data);
            order.id = atoi(data.c_str()); 
            getline(in, data);
            order.Username = data;
            getline(in, data);
            order.description = data;
            getline(in, data);
            order.status = data;
            getline(in, data);
            order.delete_status = atoi(data.c_str());
            getline(in, data);
            order_list.push_back(order);
//            order_list[order.id - 1] = order;
        }
        order_list.pop_back();
        system("pause");
        return order_list;
    }
}

//Order loadOrderFromFile() {
//
//}



void saveOrder_list(vector<Order>& order_list) { //сохранение всех заказов в файл
    fstream in;
    in.open("data.dat");
    if (in.is_open()) {
        for (Order order : order_list) {
            in << order.id << "\n" << order.Username << "\n" << order.description << "\n" << order.status << "\n" << order.delete_status << "\n*\n";
        }
    }
    else cout << "error: fuck you ass" << endl;
}