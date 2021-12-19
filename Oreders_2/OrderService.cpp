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

	bool NewOrder(string description, string status, int price) {
		Order order;
		int v = static_cast<int>(order_repo.getAll().size()) + 1;
		order.setId(v);
		order.setDelStatus(false);
		order.setUsername(UsrName);
		order.setDescription(description);
		order.setStatus(status);
		if (price >= 0) {
			order.setPrice(price);
			order_repo.saveOrder(order);
			return 0;
		}
		else {
			throw exception("Ќеверное значение стоимости");
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

	/* подумать над вводом данных, тип если по€витс€ новые пол€, то их и тут надо будет добавл€итд
	*/

	bool EditOrder(Order& ord ,string description, string status, int price) {	
		ord.setDescription(description);
		ord.setStatus(status);
		if (price >= 0) {
			ord.setPrice(price);
			order_repo.saveOrder(ord);
			return 0;
		}
		else {
			throw exception("Ќеверное значение стоимости");
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