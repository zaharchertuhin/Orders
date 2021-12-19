#include "Order.h"
#include "OrderService.cpp"

using namespace std;

int isInt();
void User_Menu();
int getLevel();

void PrintOrd(Order& ord) {
	if (ord.getDelStatus() == 0) {
	cout << "id: " << ord.getId()
		<< "\nДобавил(а): " << ord.getUsername()
		<< "\nDescription: " << ord.getDescription()
		<< "\nStatus: " << ord.getStatus()
		<< "\nPrice: " << ord.getPrice() << endl;
	}
	else throw exception();
}

OrderService orderService;

void Order_Menu() {
	bool key = true;
	while (key) {
		system("cls");
		cout << "Заказы:\n" <<
			"\t1) Добавить заказ.\n" <<
			"\t2) Показать заказы.\n" <<
			"\t3) Найти заказ.\n" <<
			"\t4) Редактировать заказ\n" <<
			"\t5) Удалить заказ.\n" <<
			"\t6) Выгрузить заказы\n" <<
			"\t7) Cумма стоимости заказов\n" <<
			"\t8) Редактровать пользователей\n" <<
			"\t9) Сохранить и выйти\n";
		int a = isInt();
		switch (a) {
		case 1: {
			try
			{
				system("cls");
				string Des, Stat;
				cout << "Введите новое описание заказа: ";
				(cin >> Des).get();
				cout << "Введите новый статус заказа: ";
				(cin >> Stat).get();
				cout << "Введите новую стоимость заказа: ";
				int val = isInt();
				orderService.NewOrder(Des, Stat, val);
			}
			catch (const std::exception& exp)
			{
				cout << "Заказ заполнен неправильно!" << endl;
				cout << "\n" << exp.what() << endl;
				system("pause");
			}
			break;
		}
		case 2: {
			system("cls");
			for (Order ord : orderService.PrintAll()) {
				if (ord.getDelStatus() == 0) {
					PrintOrd(ord);
				}
			}
			system("pause");
			break;
		}
		case 3: {
			try
			{
				system("cls");
				cout << "Enter a order id:" << endl;
				int id = isInt();
				Order ord = orderService.FindOrder(id);
				PrintOrd(ord);
			}
			catch (const std::exception& exp)
			{
				//cout << "Такого заказа нет." << endl;
				cout << "\n" << exp.what() << endl;
				system("pause");
			}
			break;
		}
		case 4: {
			try
			{
				system("cls");
				cout << "Enter a order id:" << endl;
				int id = isInt();
				Order ord = orderService.FindOrder(id);
				string Des, Stat;
				cout << "Введите новое описание заказа: ";
				(cin >> Des).get();
				cout << "Введите новый статус заказа: ";
				(cin >> Stat).get();
				cout << "Введите новую стоимость заказа: ";
				int val = isInt();
				orderService.EditOrder(ord, Des, Stat, val);
			}
			catch (const std::exception& exp)
			{
				cout << "\n" << exp.what() << endl;
				system("pause");
			}
			break;
		}
		case 5: {
			try {
				system("cls");
				cout << "Enter a order id:" << endl;
				int id = isInt();
				Order ord = orderService.FindOrder(id);
				orderService.DeleteById(ord);
			}
			catch (const std::exception& exp)
			{
				cout << "\n" << exp.what() << endl;
				system("pause");
			}
			break;
		}
		case 6: {
			try
			{
				orderService.Filling();
			}
			catch (const std::exception& exp)
			{
				cout << "\n" << exp.what() << endl;
				system("pause");
			}
			break;
		}
		case 7: {
			
			system("cls");
			cout << "Сумма стоимости заказов: " << orderService.SumOrders() << endl;
			system("pause");
			break;
		}
		case 8: {
			// допилить проверку пользователя
			int level = getLevel();
			if (level >= 2) {
				User_Menu();
			}
			else { cout << "Вы здесь ничтожество" << endl; system("pause"); }
			break;
		}
		case 9: {
			system("cls");
			orderService.Save();
			key = false;
			break;
		}
		default: {
			cout << "Месье, вы дэбил, давайте по-новой." << endl;
		}
		}
	}
}