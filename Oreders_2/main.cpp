#include "Order.h"

#include "Users.cpp"


using namespace std;

void Edit_Users(UserRepository& usrRepo);
bool StartPage(UserRepository& usrRepo);


// передлать по правилам Солида
// убрать редактирование из репозиториев 
// оставить тольк сохранение
// отвязать юзера от репозтория, шоб они были независимы дрг от друга



int main() {
	OrderRepository ordRepo;
	UserRepository usrRepo;
	//setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");
	usrRepo.filling();
	int p = 3;
	while (p > 0) {
		if (StartPage(usrRepo)) {
			
			p = 3;
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
						newOrder(ordRepo);
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
					printAll(ordRepo);
					break;
				}
				case 3: {
					try
					{
						int id = FindOrder(ordRepo);
						printOrder(ordRepo , id);
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
					int id = FindOrder(ordRepo);
					try
					{
						Order ord = EditOrder(ordRepo, id);
						ordRepo.saveOrder(ord, id);
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
						int id = FindOrder(ordRepo);
						ordRepo.deleteById(id);
					}
					catch (const std::exception& exp)
					{
						cout << "\n" << exp.what() << endl;
						system("pause");
					}
					break;
				}
				case 6: {
					
					ordRepo.filling();
					break;
				}
				case 7: {
					system("cls");
					cout << "Сумма стоимости заказов: " << sumOrders(ordRepo) << endl;
					system("pause");
					break;
				}
				case 8: {
					
					//int level =clearanceLevel(usrRepo , UsrName);
					int level = 3;
					cout << level << endl;
					if (level >= 2) {
						Edit_Users(usrRepo);
						usrRepo.Save_Users();
					}
					else { cout << "Вы здесь ничтожество" << endl; system("pause"); }
					break;
				}
				case 9: {
					system("cls");
					ordRepo.saveOrder_list();
					key = false;
					break;
				}
				default: {
					cout << "Месье, вы дэбил, давайте по-новой." << endl;
					return 0;
				}
				}
			}
		}
		else {
			p--;
		}
	}
}