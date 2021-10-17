#include "Order_Header.h"

using namespace std;

void saveOrder_list(vector<Order>& order_list);

Order orderAdd(vector<Order>& vect, string& Username);

void orderPrintAll(vector<Order>& order_list, string& Username);

Order FindOrder(vector<Order>& order_list, string& Username);

void printOrder(Order& order);

Order Edit_Order(Order& order, string& Username);

Order delete_Order(Order& order);

void saveOrders(vector<Order>& order_list, Order& order);

bool UserCheck(string& Username, string& Password, int& p);

int sumOrders(vector<Order>& order_list, string& Username);

bool StartPage();

vector<Order> load_order();

int main() {
    system("chcp 1251"); 
    system("cls");
    string Username;
    string Password;
    
    int p = 3;
    while (p > 0) {
        bool flag = StartPage();
        if (flag) {
            cout << "Login:" << endl;
            cin >> Username;
            cout << "\nPassword:" << endl;
            cin >> Password;

            if (UserCheck(Username, Password, p)) {
                p = 3;
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
                        "\t7) Количество заказов\n" <<
                        "\t8) Выход\n";

                    cin >> a;

                    switch (a) {
                    case 1: {
                        orders.push_back(orderAdd(orders, Username));
                        saveOrder_list(orders);
                        break;
                    }
                    case 2: {
                        orderPrintAll(orders, Username);
                        break;
                    }
                    case 3: {
                        Order order = FindOrder(orders, Username);
                        printOrder(order);
                        break;
                    }

                    case 4: {
                        Order order = FindOrder(orders, Username);
                        order = Edit_Order(order, Username);
                        saveOrders(orders, order);
                        saveOrder_list(orders);
                        break;
                    }

                    case 5: {
                        Order order = FindOrder(orders, Username);
                        order = delete_Order(order);
                        saveOrders(orders, order);
                        saveOrder_list(orders);
                        break;
                    }
                    case 6: {
                        orders = load_order();
                        break;
                    }
                    case 7: {
                        system("cls");
                        cout << "Количество заказов: " << sumOrders(orders, Username) << endl;
                        system("pause");
                        break;
                    }

                    case 8: {
                        system("cls");s
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
            else {

                //cout << "wrong login or password" << endl;
                p--;
            }
        }
        else if (!flag) exit(0);
        
    }
}