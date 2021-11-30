#include "Order.h"
#include "Repos.cpp"

using namespace std;

class OrderService {
public:

	Order FindOrder() {
		system("cls");
		cout << "Enter a order id:" << endl;
		int id = isInt();
		return ordRepo.get(id); // � ���� �� ������?
	}

	bool newOrder() {
		Order order;
		string line;
		system("cls");
		int v = static_cast<int>(ordRepo.getAll().size()) + 1;
		order.setId(v);
		order.setDelStatus(false);
		order.setUsername(UsrName);
		cout << "������� ����� �������� ������: ";
		(cin >> line).get();
		order.setDescription(line);
		cout << "������� ����� ������ ������: ";
		(cin >> line).get();
		order.setStatus(line);
		cout << "������� ����� ��������� ������: ";
		int val = isInt();
		if (val >= 0) {
			order.setPrice(val);
			ordRepo.saveOrder(order);
			return 0;
		}
		else {
			throw exception("�������� �������� ���������");
		}
	}

	int sumOrders() {
		int sum = 0;
		for (Order order : ordRepo.getAll()) {
			if (order.getUsername() == UsrName) {
				sum += order.getPrice();
			}
		}
		return sum;
	}

	void printOrder(Order& ord) { 
		system("cls");
		if (ord.getDelStatus() == 0) {
			cout << "id: " << ord.getId()
				<< "\n�������(�): " << ord.getUsername()
				<< "\nDescription: " << ord.getDescription()
				<< "\nStatus: " << ord.getStatus()
				<< "\nPrice: " << ord.getPrice() << endl;
			system("pause");
		}
		else throw exception();
	}

	void printAll() {
		system("cls");
		for (Order order : ordRepo.getAll()) {
			if (order.getDelStatus() == 0 && order.getUsername() == UsrName) {
				cout << "id: " << order.getId() << "\n�������(�): " << order.getUsername()
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
		cout << "������� ����� �������� ������: ";
		(cin >> line).get();
		ord.setDescription(line);
		cout << "������� ����� ������ ������: ";
		(cin >> line).get();
		ord.setStatus(line);
		cout << "������� ����� ��������� ������: ";
		int val = isInt();
		if (val >= 0) {
			ord.setPrice(val);
			ordRepo.saveOrder(ord);
			return 0;
		}
		else {
			throw exception("�������� �������� ���������");
		}
	}

private: //����� � ������ ��� ����������?
	OrderRepository ordRepo;
	string UsrName = "admin";
};