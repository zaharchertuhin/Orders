#include "Order.h"
#include "Repos.cpp"

using namespace std;

string UsrName = "admin";


int FindOrder(OrderRepository& ordRepo) {
	system("cls");
	cout << "Enter a order id:" << endl;
	int id = isInt();
	if (id <= ordRepo.getAll().size()) {
		for (Order order : ordRepo.getAll()) {
			if (order.getId() == id && order.getDelStatus() == 0 && order.getUsername() == UsrName) {
				return (id - 1);
			}
		}
	}
	else throw exception("Месье, вы дэбил");
	return -1;
}

bool newOrder(OrderRepository& ordRepo) {
	Order order;
	string line;
	system("cls");
	int v = static_cast<int>(ordRepo.getAll().size()) + 1;
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
		ordRepo.saveOrder(order);
		return 0;
	}
	else {
		throw exception("Неверное значение стоимости");
	}
}

int sumOrders(OrderRepository& ordRepo) {
	int sum = 0;
	for (Order order : ordRepo.getAll()) {
		if (order.getUsername() == UsrName) {
			sum += order.getPrice();
		}
	}
	return sum;
}

void printOrder(OrderRepository& ordRepo, int& id) { //вывод определленного заказа
	system("cls");
	if (ordRepo.getAll()[id].getDelStatus() == 0) {
		cout << "id: " << ordRepo.getAll()[id].getId()
			<< "\nДобавил(а): " << ordRepo.getAll()[id].getUsername()
			<< "\nDescription: " << ordRepo.getAll()[id].getDescription()
			<< "\nStatus: " << ordRepo.getAll()[id].getStatus()
			<< "\nPrice: " << ordRepo.getAll()[id].getPrice() << endl;
		system("pause");
	}
	else throw exception();
}

void printAll(OrderRepository& ordRepo) {
	system("cls");
	for (Order order : ordRepo.getAll()) {
		if (order.getDelStatus() == 0 && order.getUsername() == UsrName) {
			cout << "id: " << order.getId() << "\nДобавил(а): " << order.getUsername()
				<< "\nDescription: " << order.getDescription()
				<< "\nStatus: " << order.getStatus()
				<< "\nPrice: " << order.getPrice() << endl;
		}
	}
	system("pause");
}

Order EditOrder(OrderRepository& ordRepo , int& id) {
	system("cls");
	string line = "";
	ordRepo.getAll()[id].setUsername(UsrName);
	cout << "Введите новое описание заказа: ";
	(cin >> line).get();
	ordRepo.getAll()[id].setDescription(line);
	cout << "Введите новый статус заказа: ";
	(cin >> line).get();
	ordRepo.getAll()[id].setStatus(line);
	cout << "Введите новую стоимость заказа: ";
	int val = isInt();
	if (val >= 0) {
		ordRepo.getAll()[id].setPrice(val);
		return ordRepo.getAll()[id];
	}
	else {
		throw exception("Неверное значение стоимости");
	}
}