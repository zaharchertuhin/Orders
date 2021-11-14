#include "Order.h"

using namespace std;

Order orderAdd(vector<Order>& vect, string& Username);
Order FindOrder(vector<Order>& order_list, string& Username);
Order Edit_Order(Order& order, string& Username, bool showOrd);
Order delete_Order(Order& order);
Order pshBckOrdr(vector<Order>& order_list);

void saveOrder_list(vector<Order>& order_list);
void orderPrintAll(vector<Order>& order_list, string& Username);
void printOrder(Order& order);
void saveToVector(vector<Order>& order_list, Order& order);
void Edit_Users(vector<Users>& signIn);
void Save_Users(vector<Users>& signIn);

bool UserCheck(string& Username, string& Password, vector<Users>& Login);
int sumOrders(vector<Order>& order_list, string& Username);
bool StartPage(vector<Users>& signIn);
int isInt();
int clearanceLevel(string& Username, vector<Users>& Login);

vector<Users> Logins();
vector<Order> load_order();

string Username, Password;

Users Registration(vector<Users>& Login);

string base64_encode(std::string const& s, bool url);

int main() {
	
	//setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");
	vector<Users> signIn = Logins();
	int p = 3;
	while (p > 0) {
		if (StartPage(signIn)) {
			p = 3;
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
					"\t8) ������������ �������������\n" <<
					"\t9) ��������� � �����\n";
				int a = isInt();
				switch (a) {
				case 1: {
					try
					{
						Order ord = orderAdd(orders, Username);
						orders.push_back(ord);
					}
					catch (const std::exception&)
					{
						cout << "����� �������� �����������!" << endl;
						system("pause");
					}
					saveOrder_list(orders);
					break;
				}
				case 2: {
					orderPrintAll(orders, Username);
					break;
				}
				case 3: {
					try
					{
						Order order = FindOrder(orders, Username);
						printOrder(order);
					}
					catch (const std::exception&)
					{
						cout << "������ ������ ���." << endl;
						system("pause");
					}
					break;
				}
				case 4: {
					Order order = FindOrder(orders, Username);
					try
					{
						order = Edit_Order(order, Username, true);
						saveToVector(orders, order);
					}
					catch (const std::exception& ex)
					{
						cout << "\n" << ex.what() << endl;
						system("pause");
					}
					saveOrder_list(orders);
					break;
				}
				case 5: {
					Order order = FindOrder(orders, Username);
					order = delete_Order(order);
					if (order.id != 0)saveToVector(orders, order);
					saveOrder_list(orders);
					break;
				}
				case 6: {
					vector<Order> n = load_order();
					n.push_back(pshBckOrdr(orders));
					break;
				}
				case 7: {
					system("cls");
					cout << "����� ��������� �������: " << sumOrders(orders, Username) << endl;
					system("pause");
					break;
				}
				case 8: {
					int level = clearanceLevel(Username, signIn);
					cout << level << endl;
					if (level >= 2) {
						Edit_Users(signIn);
						Save_Users(signIn);
					}
					else { cout << "�� ����� �����������" << endl; system("pause"); }
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
				}
			}
		}
		else {
			p--;
		}
	}
}