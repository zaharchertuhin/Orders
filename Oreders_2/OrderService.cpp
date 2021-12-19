#include "Order.h"
#include "OrderRepository.cpp"

using namespace std;

class OrderService {
private: 
	OrderRepository order_repo;
	string UsrName = "admin";

public:

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

	vector<Order> PrintAll() {
		return order_repo.getAll();
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