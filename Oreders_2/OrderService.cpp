#include "Order.h"
#include "OrderRepository.cpp"

using namespace std;

class OrderService {
private: 
	OrderRepository order_repo;
	string user_name = "admin";

public:

	Order FindOrder(int id) {
		return order_repo.get(id);
	}

	bool NewOrder(string description, string starus, int price) {
		Order order;
		int id = static_cast<int>(order_repo.getAll().size()) + 1;
		order.setId(id);
		order.setDelStatus(false);
		order.setUsername(user_name);
		order.setDescription(description);
		order.setStatus(starus);
		if (price >= 0) {
			order.setPrice(price);
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
			if (order.getUsername() == user_name) {
				sum += order.getPrice();
			}
		}
		return sum;
	}

	vector<Order> PrintAll() {
		return order_repo.getAll();
	}

	//TODO : Пересылать класс?
	bool EditOrder(Order& ord, string Des, string Stat, int pric) {	
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