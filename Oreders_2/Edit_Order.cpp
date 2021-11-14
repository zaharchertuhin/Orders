#include "Order.h"

using namespace std;

void saveToFile(Order& order);
Order Edit_Order(Order& order, string& Username, bool showOrd);
int isInt();

Order orderAdd(vector<Order>& order_list, string& Username) { // ���������� ������
	Order order;
	system("cls");
	order.id = static_cast<int>(order_list.size()) + 1;
	order.delete_status = false;
    order = Edit_Order(order, Username, false);
    return order;
}

Order Edit_Order(Order& order, string& Username, bool showOrd) { // ��������� ������
    system("cls");
	if (order.delete_status == true) {
        throw exception("����� ������");
	}
    if (showOrd) {
        cout << "id: " << order.id << "\n�������(�): " << order.Username << "\nDescription: " << order.description << "\nStatus: " << order.status << "\nPrice: " << order.price << "\n\n";
    }
	order.Username = Username;
    cout << "������� ����� �������� ������: ";
    (cin >> order.description).get();
    cout << "������� ����� ������ ������: ";
    (cin >> order.status).get();
    cout << "������� ����� ��������� ������: ";
    int val = isInt();
	if (val >= 0) {
		order.price = val;
		saveToFile(order);
		return order;
	}
	else {
		throw exception("�������� �������� ���������");
	}
}

Order delete_Order(Order& order) { //�������� ������
    system("cls");
    order.delete_status = 1;
    return order;
}
