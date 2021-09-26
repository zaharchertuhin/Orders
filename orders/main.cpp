#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Order_Header.h"

using namespace std;

struct Order;

void orderAdd(vector<Order>& vect);

void orderPrintAll(vector<Order>& vect);

void orderFind(vector<Order>& vect);

void redact_Order(vector<Order>& vect);

void deletorder(vector<Order>& vect);

void load_order(vector<Order>& vect);

int main() {
    system("chcp 1251"); // for Clion use "chcp 65001"
    int a;
    vector<Order> orders;
    bool key = true;
    while (key) {
        system("cls");

        cout << "Çàêàçû:\n" <<
            "\t1) Äîáàâèòü çàêàç.\n" <<
            "\t2) Ïîêàçàòü çàêàçû.\n" <<
            "\t3) Íàéòè çàêàç.\n" <<
            "\t4) Ðåäàêòèðîâàòü çàêàç\n" <<
            "\t5) Óäàëèòü çàêàç.\n" <<
            "\t6) Âûãðóçèòü çàêàçû\n" <<
            "\t7) Âûõîä\n";
        cin >> a;

        switch (a) {
        case 1: {
            orderAdd(orders);
            break;
        }
        case 2: {
            orderPrintAll(orders);
            break;
        }
        case 3: {
            orderFind(orders);
            break;
        }

        case 4: {
            redact_Order(orders);
            break;
        }

        case 5: {
            deletorder(orders);
            break;
        }
        case 6: {
            load_order(orders);
            break;
        }

        case 7: {
            key = false;
            break;
        }

        default: {
            cout << "Ìåñüå, âû äýáèë, äàâàéòå ïî-íîâîé." << endl;
            return 0;
        }
        };
    }
}