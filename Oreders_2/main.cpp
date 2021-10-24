#include "Order.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>


using namespace std;

void saveOrder_list(vector<Order>& order_list);

Order orderAdd(vector<Order>& vect, string& Username);

void orderPrintAll(vector<Order>& order_list, string& Username);

Order FindOrder(vector<Order>& order_list, string& Username);

void printOrder(Order& order);

Order Edit_Order(Order& order, string& Username);

Order delete_Order(Order& order);

void saveOrders(vector<Order>& order_list, Order& order);

bool UserCheck(string& Username, string& Password, vector<Users> Login);

int sumOrders(vector<Order>& order_list, string& Username);

vector<Users> Login();

bool StartPage();

vector<Order> load_order(vector<Order>& orders);

string Username;

string Password;

bool sort_orders(Order first, Order second) {
	return (first.id < second.id);
}

int main() {
	system("chcp 1251");
	system("cls");
	vector<Users> signIn = { {"admin", "password"},{"user", "1234"} };

	int p = 3;
	while (p > 0) {
		bool strt_pg = StartPage();

		cout << "Осталось попыток: " << p - 1 << endl;
		if (strt_pg) {
			cout << "Login:" << endl;
			cin >> Username;
			cout << "Password:" << endl;
			cin >> Password;
			bool usr_chk = UserCheck(Username, Password, signIn);
			if (usr_chk) {
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
						"\t8) Сохранить и выйти\n";

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
						vector<Order> n = load_order(orders);
						sort(n.begin(), n.end(), sort_orders);
						orders = n;
						break;
					}

					case 7: {
						system("cls");
						cout << "Сумма стоимости заказов: " << sumOrders(orders, Username) << endl;
						system("pause");
						break;
					}

					case 8: {
						system("cls");
						saveOrder_list(orders);
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
				p--;
			}
		}
		else if (!strt_pg) exit(0);

	}
}