//#include "Order.h"
//#include "Repos.cpp"
//
//using namespace std;
//
//string UsrName = "admin";
//
//OrderRepository ordRepo;
//
//Order FindOrder() {
//	system("cls");
//	cout << "Enter a order id:" << endl;
//	int id = isInt();
//	return ordRepo.get(id);
//	
//}
//
//bool newOrder() {
//	Order order;
//	string line;
//	system("cls");
//	int v = static_cast<int>(ordRepo.getAll().size()) + 1;
//	order.setId(v);
//	order.setDelStatus(false);
//	order.setUsername(UsrName);
//	cout << "Введите новое описание заказа: ";
//	(cin >> line).get();
//	order.setDescription(line);
//	cout << "Введите новый статус заказа: ";
//	(cin >> line).get();
//	order.setStatus(line);
//	cout << "Введите новую стоимость заказа: ";
//	int val = isInt();
//	if (val >= 0) {
//		order.setPrice(val);
//		ordRepo.saveOrder(order);
//		return 0;
//	}
//	else {
//		throw exception("Неверное значение стоимости");
//	}
//}
//
//int sumOrders() {
//	int sum = 0;
//	for (Order order : ordRepo.getAll()) {
//		if (order.getUsername() == UsrName) {
//			sum += order.getPrice();
//		}
//	}
//	return sum;
//}
//
//void printOrder(Order& ord) { //вывод определленного заказа
//	system("cls");
//	if (ord.getDelStatus() == 0) {
//		cout << "id: " << ord.getId()
//			<< "\nДобавил(а): " << ord.getUsername()
//			<< "\nDescription: " << ord.getDescription()
//			<< "\nStatus: " << ord.getStatus()
//			<< "\nPrice: " << ord.getPrice() << endl;
//		system("pause");
//	}
//	else throw exception();
//}
//
//void printAll() {
//	system("cls");
//	for (Order order : ordRepo.getAll()) {
//		if (order.getDelStatus() == 0 && order.getUsername() == UsrName) {
//			cout << "id: " << order.getId() << "\nДобавил(а): " << order.getUsername()
//				<< "\nDescription: " << order.getDescription()
//				<< "\nStatus: " << order.getStatus()
//				<< "\nPrice: " << order.getPrice() << endl;
//		}
//	}
//	system("pause");
//}
//
//Order EditOrder(int& id) { //взять ордер из репы, изменить а потом сохраниеть
//	system("cls");
//	string line = "";
//	ordRepo.get(id).setUsername(UsrName);
//	cout << "Введите новое описание заказа: ";
//	(cin >> line).get();
//	ordRepo.get(id).setDescription(line);
//	cout << "Введите новый статус заказа: ";
//	(cin >> line).get();
//	ordRepo.get(id).setStatus(line);
//	cout << "Введите новую стоимость заказа: ";
//	int val = isInt();
//	if (val >= 0) {
//		ordRepo.get(id).setPrice(val);
//		return ordRepo.get(id);
//	}
//	else {
//		throw exception("Неверное значение стоимости");
//	}
//}