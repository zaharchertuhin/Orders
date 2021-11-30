#include "Order.h"
using namespace std;

void Edit_Users();
bool StartPage();
int isInt();


// redact orderc.cpp / see comments
// OrderService  eto class
// UserService eto toze class
// послушать диктофон, помотреть фоточку
// создать юзерхидер
// раскидать все по папкам юзер ордер коммон
// 
// занятся архиектурой нарисоват схему
// 
// сделать сначал микросервис, потом показать Давиду
// 
// создать ветку на основе мстера
//
// глянуть ветку у Давида, а именно сервисы 
// можно взять логику
// 
//
//в реопзитории куча простых сревисов
// вся логика в сервисе

/**
* Это крайне тяжело читать, пока хз что со всем этим безобразием делать
*/
int main() {
	//setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");
	int p = 3;
	while (p > 0) {
		if (StartPage()) {
			
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
						cout << "not working, sorry(";
						break;
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
					cout << "not working, sorry(";
					break;
				}
				case 3: {
					try
					{
						cout << "not working, sorry(";
						break;
						/*int id = isInt();
						Order ord = FindOrder(id);
						printOrder(ord);*/
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
					//int id = FindOrder(ordRepo);
					try
					{
						cout << "not working, sorry(";
						break;
						/*Order ord = EditOrder(ordRepo, id);
						ordRepo.saveOrder(ord, id);*/
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
						cout << "not working, sorry(";
						break;
						/*int id = FindOrder(ordRepo);
						ordRepo.deleteById(id);*/
					}
					catch (const std::exception& exp)
					{
						cout << "\n" << exp.what() << endl;
						system("pause");
					}
					break;
				}
				case 6: {
					cout << "not working, sorry(";
					break;
					//ordRepo.filling();
					break;
				}
				case 7: {
					cout << "not working, sorry(";
					break;
					/*system("cls");
					cout << "Сумма стоимости заказов: " << sumOrders(ordRepo) << endl;
					system("pause")*/;
					break;
				}
				case 8: {
					
					//int level =clearanceLevel(usrRepo , UsrName);
					int level = 3;
					cout << level << endl;
					if (level >= 2) {
						Edit_Users();
						//usrRepo.Save_Users();
					}
					else { cout << "Вы здесь ничтожество" << endl; system("pause"); }
					break;
				}
				case 9: {
					system("cls");
					//ordRepo.saveOrder_list();
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