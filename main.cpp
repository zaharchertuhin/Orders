#include "Order.h"
#include<ctime>
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

int UserCheck(string& Username, string& Password, vector<Users> Login);

int sumOrders(vector<Order>& order_list, string& Username);

vector<Users> Login();

int StartPage();

vector<Order> load_order(vector<Order>& orders);

string Username;

string Password;

void Edit_Users(vector<Users>& signIn, int& usr_chk);

void Save_Users(vector<Users>& signIn);

Users SignUp();

bool sort_orders(Order first, Order second) {
	return (first.id < second.id);
}

int main() {
	//setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");
	vector<Users> signIn = Login();// { {"admin", "password"}, { "user", "1234" } };

	int p = 3;
	while (p > 0) {
		int strt_pg = StartPage();
		switch (strt_pg)
		{
		default:break;
		
		case 1: {
			exit(0);
		}
		case 2: {
			signIn.push_back(SignUp());
			system("cls");
			break;
		}
		case 0: {
			cout << "�������� �������: " << p << endl;
			cout << "Login:" << endl;
			cin >> Username;
			cout << "Password:" << endl;
			cin >> Password;
			int usr_chk = UserCheck(Username, Password, signIn);
			if (usr_chk != 0) {
				p = 3;
				int a;
				vector<Order> orders;
				bool key = true;
				while (key) {
					system("cls");

					cout << "������:\n" <<
						"\t1) �������� �����.\n" <<
						"\t2) �������� ������.\n" <<
						"\t3) ����� �����.\n" <<
						"\t4) ������������� �����\n" <<
						"\t5) ������� �����.\n" <<
						"\t6) ��������� ������\n" <<
						"\t7) C���� ��������� �������\n" <<
						"\t8) ������������ �������������\n"<<
						"\t9) ��������� � �����\n";
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
						//sort(n.begin(), n.end(), sort_orders);
						orders = n;
						break;
					}

					case 7: {
						system("cls");
						cout << "����� ��������� �������: " << sumOrders(orders, Username) << endl;
						system("pause");
						break;
					}
					case 8: {
						if (usr_chk >= 2) {
							Edit_Users(signIn, usr_chk);
							Save_Users(signIn);
						}
						else {
							cout << "� ��� ��� �������" << endl;
							system("pause");
						}
						break;
					}

					case 9: {
						system("cls");
						saveOrder_list(orders);
						key = false;
						break;
					}
					default: {
						cout << "�����, �� �����, ������� ��-�����." << endl;
						return 0;
					}
					};
				}
			}

			else {
				p--;
			}
		}
		}
	}
}