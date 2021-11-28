#include "Order.h"

#include "Users.cpp"


using namespace std;

void Edit_Users(UserRepository& usrRepo);
bool StartPage(UserRepository& usrRepo);


// ��������� �� �������� ������
// ������ �������������� �� ������������ 
// �������� ����� ����������
// �������� ����� �� ����������, ��� ��� ���� ���������� ��� �� �����



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
						newOrder(ordRepo);
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
						cout << "������ ������ ���." << endl;
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
					cout << "����� ��������� �������: " << sumOrders(ordRepo) << endl;
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
					else { cout << "�� ����� �����������" << endl; system("pause"); }
					break;
				}
				case 9: {
					system("cls");
					ordRepo.saveOrder_list();
					key = false;
					break;
				}
				default: {
					cout << "�����, �� �����, ������� ��-�����." << endl;
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