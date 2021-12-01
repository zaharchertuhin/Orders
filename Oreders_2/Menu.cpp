#include "Order.h"
#include "OrderService.cpp"

using namespace std;

int isInt();
void Edit_Users();
int getLevel();

OrderService orderService;

void Menu() {
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
				orderService.NewOrder();
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
			orderService.PrintAll();
			break;
		}
		case 3: {
			try
			{
				Order ord = orderService.FindOrder();
				orderService.PrintOrder(ord);
			}
			catch (const std::exception& exp)
			{
				cout << "Такого заказа нет." << endl;
				cout << "\n" << exp.what() << endl;
				system("pause");
			}
			break;
		}
		case 4: {
			try
			{
				Order ord = orderService.FindOrder();
				orderService.EditOrder(ord);
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
				Order ord = orderService.FindOrder();
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
			cout << level << endl;
			if (level >= 2) {
				Edit_Users();
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