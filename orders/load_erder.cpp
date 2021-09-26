#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Order_Header.h"

using namespace std;

struct Order;

void load_order(vector<Order>& vect) {
    system("cls");
    ifstream in;
    string data;
    int i = 0;
    in.open("data.dat", ios::app);
    if (in.is_open())
    {
        Order orders;
        while (!in.eof()) {
            getline(in, data, '*');
            int str_num = 0;
            string str;
            while (true) {
                str = data.substr(0, data.find("\n"));
                if (str.size() != 0) {
                    switch (str_num) {
                    case 0:
                        orders.id = vect.size() + 1;
                        cout << "id: " << str << endl;
                        break;
                    case 1:
                        orders.description = str;
                        cout << "des: " << str << endl;
                        break;
                    case 2:
                        orders.status = str;
                        cout << "stat: " << str << endl;
                        break;
                    case 3:
                        if (str == "True") {
                            orders.delete_status = true;
                        }
                        else if (str == "False") {
                            orders.delete_status = false;
                        }
                        cout << "delst: " << str << endl;
                        break;
                    }
                    str_num++;

                }
                if (str.size() == data.size()) {
                    cout << "save " << endl;
                    vect.push_back(orders);
                    break;
                }
                else data = data.substr(str.size() + 1);
            }
            i++;
        }
        in.close();
        vect.pop_back();
    }
    else {
        cout << "The order was not found. Please try again.\n";
    }
    system("pause");
}