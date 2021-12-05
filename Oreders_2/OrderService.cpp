#include "Order.h"
#include "OrderRepository.cpp"

using namespace std;

class OrderService {
private: 
	OrderRepository order_repo;
	string UsrName = "admin";

public:

	void CoutOrd(Order& ord) {
		cout << "id: " << ord.getId()
			<< "\nДобавил(а): " << ord.getUsername()
			<< "\nDescription: " << ord.getDescription()
			<< "\nStatus: " << ord.getStatus()
			<< "\nPrice: " << ord.getPrice() << endl;
	}

	Order FindOrder(int id) {
		return order_repo.get(id);
	}

	bool NewOrder(string Des, string Stat, int pric) {
		Order order;
		int v = static_cast<int>(order_repo.getAll().size()) + 1;
		order.setId(v);
		order.setDelStatus(false);
		order.setUsername(UsrName);
		order.setDescription(Des);
		order.setStatus(Stat);
		if (pric >= 0) {
			order.setPrice(pric);
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
		if (ord.getDelStatus() == 0) {
			CoutOrd(ord);
			system("pause");
		}
		else throw exception();
	}

	void PrintAll() {
		system("cls");
		for (Order order : order_repo.getAll()) {
			if (order.getDelStatus() == 0 && order.getUsername() == UsrName) {
				CoutOrd(order);
			}
		}
		system("pause");
	}

	bool EditOrder(Order& ord ,string Des, string Stat, int pric) {	
		ord.setDescription(Des);
		ord.setStatus(Stat);
		if (pric >= 0) {
			ord.setPrice(pric);
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