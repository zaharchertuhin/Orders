#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include "Order_Header.h"

using namespace std;

struct Order;

void orderPrintAll(vector<Order>& vect) {
    system("cls");
    fstream in;
    string data;
    in.open("data.dat", ios::app);
    if (in.is_open())
    {
        cout << vect.size() << endl;
        for (int i = 0; i < vect.size(); i++) {
            if (vect[i].delete_status == false) {
                cout << " id: " << vect[i].id << "\nDescription " << vect[i].description << "\nStatus " << vect[i].status << endl;
            }
        }
        in.close();

    }
    else {
        cout << "The order was not found. Please try again.\n";
    }
    system("pause");
}

void orderFind(vector<Order>& vect) {
    system("cls");
    int orderid;
    cout << "Ââåäèòå Íîìåð Çàêàçà" << endl;
    cin >> orderid;
    ifstream in;
    string data;
    in.open("data.dat", ios::app);
    if (in.is_open())
    {

        for (int i = 0; i < vect.size(); i++) {
            getline(in, data, '*');
            if (data.find(to_string(orderid)) != string::npos) {
                if (data.find("True") != string::npos)cout << "Order was deleted" << endl;
                else {
                    cout << " id: " << vect[i].id << "\nDescription " << vect[i].description << "\nStatus " << vect[i].status << endl;
                }
                in.close();
            }
        }
    }
    else {
        cout << "The order was not found. Please try again.\n";
    }
    system("pause");
}