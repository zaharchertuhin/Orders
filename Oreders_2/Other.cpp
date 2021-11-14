#include "Order.h"
using namespace std;

int isInt() {
	string input;
	cin >> input;
	bool valid = true;
	for (int i = 0; i < input.size(); i++) {
		if (!isdigit(input[i])) {
			valid = false;
		}
	}
	if (valid) {
		return stoi(input);
	}
	return -1;
}

int clearanceLevel(string& Username, vector<Users>& Login) {
	for (int i = 0; i < Login.size(); i++) {
		if (Login[i].login == Username) {
			return Login[i].status;
		}
	}
}