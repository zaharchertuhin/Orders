#include "Order.h"
#include "Repos.cpp"

using namespace std;

void Edit_Users(UserRepository& usrRepo);
bool StartPage(UserRepository& usrRepo, OrderRepository& ordRepo);
int isInt();

int main() {
	OrderRepository ordRepo;
	UserRepository usrRepo;
	//setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");
	usrRepo.filling();
	int p = 3;
	while (p > 0) {
		if (StartPage(usrRepo, ordRepo)) {
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
						ordRepo.newOrder();
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
					ordRepo.printAll();
					break;
				}
				case 3: {
					try
					{
						int id = ordRepo.FindOrder();
						ordRepo.printOrder(id);
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
					int id = ordRepo.FindOrder();
					try
					{
						ordRepo.EditOrder(id);
					}
					catch (const std::exception& exp)
					{
						cout << "\n" << exp.what() << endl;
						system("pause");
					}
					
					break;
				}
				case 5: {
					int id = ordRepo.FindOrder();
					ordRepo.deleteOrder(id);
					
					break;
				}
				case 6: {
					
					ordRepo.filling();
					break;
				}
				case 7: {
					system("cls");
					cout << "����� ��������� �������: " << ordRepo.sumOrders() << endl;
					system("pause");
					break;
				}
				case 8: {
					string Username = ordRepo.getUser();
					int level =usrRepo.clearanceLevel(Username);
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