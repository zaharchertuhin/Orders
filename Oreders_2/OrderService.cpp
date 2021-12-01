#include "Order.h"
#include "OrderRepository.cpp"

using namespace std;

class OrderService {
private: 
	OrderRepository order_repo;
	string UsrName = "admin";

public:

	Order FindOrder() {
		system("cls");
		cout << "Enter a order id:" << endl;
		int id = isInt();
		return order_repo.get(id);
	}

	bool NewOrder() {
		Order order;
		string line;
		system("cls");
		int v = static_cast<int>(order_repo.getAll().size()) + 1;
		order.setId(v);
		order.setDelStatus(false);
		order.setUsername(UsrName);
		cout << "Введите новое описание заказа: ";
		(cin >> line).get();
		order.setDescription(line);
		cout << "Введите новый статус заказа: ";
		(cin >> line).get();
		order.setStatus(line);
		cout << "Введите новую стоимость заказа: ";
		int val = isInt();
		if (val >= 0) {
			order.setPrice(val);
			order_repo.saveOrder(order);
			return 0;
		}
		else {
			throw exception("Неверное значение стоимости");
		}
	}

	int SumOrders() {
		int sum = 0;
		for (Order order : order_repo.getAll()) {
			if (order.getUsername() == UsrName) {
				sum += order.getPrice();
			}
		}
		return sum;
	}

	void PrintOrder(Order& ord) { 
		system("cls");
		if (ord.getDelStatus() == 0) {
			cout << "id: " << ord.getId()
				<< "\nДобавил(а): " << ord.getUsername()
				<< "\nDescription: " << ord.getDescription()
				<< "\nStatus: " << ord.getStatus()
				<< "\nPrice: " << ord.getPrice() << endl;
			system("pause");
		}
		else throw exception();
	}

	void PrintAll() {
		system("cls");
		for (Order order : order_repo.getAll()) {
			if (order.getDelStatus() == 0 && order.getUsername() == UsrName) {
				cout << "id: " << order.getId() << "\nДобавил(а): " << order.getUsername()
					<< "\nDescription: " << order.getDescription()
					<< "\nStatus: " << order.getStatus()
					<< "\nPrice: " << order.getPrice() << endl;
			}
		}
		system("pause");
	}

	bool EditOrder(Order& ord) {
		system("cls");
		string line = "";
		ord.setUsername(UsrName);
		cout << "Введите новое описание заказа: ";
		(cin >> line).get();
		ord.setDescription(line);
		cout << "Введите новый статус заказа: ";
		(cin >> line).get();
		ord.setStatus(line);
		cout << "Введите новую стоимость заказа: ";
		int val = isInt();
		if (val >= 0) {
			ord.setPrice(val);
			order_repo.saveOrder(ord);
			return 0;
		}
		else {
			throw exception("Неверное значение стоимости");
		}
	}

	bool DeleteById(Order& ord) {
		int i = ord.getId();
		order_repo.deleteById(i);
		return 0;
	}

	bool Filling() {
		order_repo.filling();
		return 0;
	}

	bool Save() {
		order_repo.saveOrderList();
		return 0;
	}
};