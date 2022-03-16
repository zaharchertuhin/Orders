#include "Order.h"
using namespace std;

bool StartPage();
void Order_Menu();

void fill();

int main() {
	fill();
	//setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");
	int p = 3;
	while (p > 0) {
		if (StartPage()) {
			p = 3;
			Order_Menu();
		}
		else {
			p--;
		}
	}
	return 0;
}