#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Order_Header.h"

using namespace std;

struct Order;

void orderAdd(vector<Order>& vect) {
    system("cls");
    Order neworder;
    neworder.id = vect.size() + 1;
    neworder.delete_status = false;
    cout << "Ââåäèòå îïèñàíèå çàêàçà: ";
    getline(cin, neworder.description);
    cin >> neworder.description;
    cout << "Ââåäèòå ñòàòóñ çàêàçà: ";
    cin >> neworder.status;
    vect.push_back(neworder);
    ofstream out;
    out.open("data.dat", ios::app);
    if (out.is_open())
    {
        out << neworder.id << "\n" << neworder.description << "\n" << neworder.status << "\n";
        if (neworder.delete_status == false) out << "False" << "\n";
        out << "*" << endl;
        out.close();
    }
}

void redact_Order(vector<Order>& vect) {
    system("cls");
    int orderid;
    cout << "Ââåäèòå Íîìåð Çàêàçà: " << endl;
    cin >> orderid;
    ofstream out;
    string data, description, status;
    out.open("data.dat");
    out << "";
    out.close();
    cout << "Ââåäèòå îïèñàíèå çàêàçà: ";
    cin >> description;
    //getline(cin, description, '.');
    cout << "Ââåäèòå ñòàòóñ çàêàçà: ";
    cin >> status;
    //getline(cin, status, '.');
    for (int i = 0; i < vect.size(); i++) {
        for (auto x : vect) {
            if (i == orderid) {
                if (vect[i].delete_status == false) {
                    vect[orderid - 1].description = description;
                    vect[orderid - 1].status = status;
                    cout << "ok" << endl;
                    break;
                }
                else cout << "Order was deleted";
            }
        }
        out.open("data.dat", ios::app);
        if (out.is_open())
        {
            out << vect[i].id << "\n" << vect[i].description << "\n" << vect[i].status << "\n";
            if (vect[i].delete_status == false) out << "False" << "\n";
            out << "*" << endl;
            out.close();
            cout << "Save...";

        }
        else {
            cout << "The order was not found. Please try again.\n";
        }
    }
    system("pause");
}

void deletorder(vector<Order>& vect) {
    system("cls");
    int orderid;
    cout << "Ââåäèòå Íîìåð Çàêàçà: " << endl;
    cin >> orderid;
    ofstream out;
    out.open("data.dat");
    out << "";
    out.close();
    for (int i = 0; i < vect.size(); i++) {
        for (auto x : vect) {
            if (i == orderid - 1) {
                vect[orderid - 1].delete_status = true;
                cout << "ok" << endl;
                break;
            }
        }
        out.open("data.dat", ios::app);
        if (out.is_open())
        {
            out << vect[i].id << "\n" << vect[i].description << "\n" << vect[i].status << "\n";
            if (vect[i].delete_status == false) out << "False" << "\n";
            else out << "True" << "\n";
            out << "*" << endl;
            out.close();
        }
        else {
            cout << "The order was not found. Please try again.\n";
        }
    }
    system("pause");
}