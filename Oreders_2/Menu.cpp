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
		cout << "������:\n" <<
			"\t1) �������� �����.\n" <<
			"\t2) �������� ������.\n" <<
			"\t3) ����� �����.\n" <<
			"\t4) ������������� �����\n" <<
			"\t5) ������� �����.\n" <<
			"\t6) ��������� ������\n" <<
			"\t7) C���� ��������� �������\n" <<
			"\t8) ������������ �������������\n" <<
			"\t9) ��������� � �����\n";
		int a = isInt();
		switch (a) {
		case 1: {
			try
			{
				orderService.NewOrder();
			}
			catch (const std::exception& exp)
			{
				cout << "����� �������� �����������!" << endl;
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
				cout << "������ ������ ���." << endl;
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
			cout << "����� ��������� �������: " << orderService.SumOrders() << endl;
			system("pause");
			break;
		}
		case 8: {
			// �������� �������� ������������
			int level = getLevel();
			cout << level << endl;
			if (level >= 2) {
				Edit_Users();
			}
			else { cout << "�� ����� �����������" << endl; system("pause"); }
			break;
		}
		case 9: {
			system("cls");
			orderService.Save();
			key = false;
			break;
		}
		default: {
			cout << "�����, �� �����, ������� ��-�����." << endl;
		}
		}
	}
}