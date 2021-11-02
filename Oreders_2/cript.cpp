#include <string>
#include <iostream>
using namespace std;

//Функция шифрования
string Encode(string& Text)
{
	//int j = 0;
	string result = "";
	for (int i = 0; i < Text.size(); i++) {
		Text[i] = Text[i] + 20;
		result += Text[i];
	}
	return result;
}

//Функция дешифрования
string Decode(string& Text)
{
	//int j = 0;
	string result = "";
	for (int i = 0; i < Text.size(); i++) {
		Text[i] = Text[i] - 20;
		result += Text[i];
	}
	return result;
}