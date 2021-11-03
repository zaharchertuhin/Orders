#include "Order.h"

using namespace std;

void saveOrder(Order& order);

Order orderAdd(vector<Order>& order_list, string& Username) { // äîáàâëåíèå çàêàçà
    Order order;
    system("cls");
    string val;
    order.id = static_cast<int>(order_list.size()) + 1;
    order.delete_status = false;
    order.Username = Username;
    cout << "Ââåäèòå îïèñàíèå çàêàçà: ";
    (cin >> order.description).get();
    cout << "Ââåäèòå ñòàòóñ çàêàçà: ";
    (cin >> order.status).get();
    cout << "Ââåäèòå ñòîèìîñòü çàêàçà: ";
    cin >> val;
	if (isdigit(val[0])) {
		order.price = stoi(val); 
        saveOrder(order);
		return order;
	}
    else {
        cout << "Çàêàç çàïîëíåí íåïðàâèëüíî!" << endl;
        system("pause");
        Order ordrer;
        return ordrer;
    }

}

Order Edit_Order(Order& order, string& Username) { // èçìåíåíèå çàêàçà
    system("cls");

	if (order.delete_status == 1) {
		Order ordrer;
		return ordrer;
	}
	string val;
	order.Username = Username;

    cout << "Ââåäèòå îïèñàíèå çàêàçà: ";
    (cin >> order.description).get();
    cout << "Ââåäèòå ñòàòóñ çàêàçà: ";
    (cin >> order.status).get();
    cout << "Ââåäèòå ñòîèìîñòü çàêàçà: ";
    cin >> val;
    if (isdigit(val[0])) {
        order.price = stoi(val);
        saveOrder(order);
        system("pause");
        return order;
    }
    else {

        cout << "Çàêàç çàïîëíåí íåïðàâèëüíî!" << endl;
        system("pause");
        Order ordrer;
        return ordrer;

    }
}

Order delete_Order(Order& order) { //óäàëåíèå çàêàçà
    system("cls");
    order.delete_status = 1;
    return order;
}

void saveOrders(vector<Order>& order_list, Order& order) { //ñîõðàíåíèå çàêàçà â âåêòîð
    system("cls");
    uint32_t i = order.id - 1;
    order_list[i] = order;
}

void saveOrder(Order& order) { //ñîõðàíåíèå çàêàçà â ôàéë ïðè ðåäàêòèðîâàíèè
    fstream in;
    in.open("data.dat");
    if (in.is_open()) {
        in << order.id << "\n" << order.Username << "\n" << order.description << "\n" << order.status << "\n" << order.price << "\n" << order.delete_status << "\n*\n";
    }
    in.close();
}