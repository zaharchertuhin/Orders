#include "Order.h"
using namespace std;

bool StartPage();
void Menu();

int main() {
	//setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");
	int p = 3;
	while (p > 0) {
		if (StartPage()) {
			p = 3;
			Menu();
		}
		else {
			p--;
		}
	}
	return 0;
}