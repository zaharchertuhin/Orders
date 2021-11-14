#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Order {
    std::string Username;
    int id = 0;
    std::string description;
    std::string status;
    int price = 0;
    bool delete_status = 1;
};

struct Users {
    std::string login;
    std::string password;
    int status = 1;
};

//class orderRepository
//{
//public:
//	
//
//	vector<Order>& order_list;
//
//	void Save() { //сохранение всех заказов в файл
//		fstream inf;
//		inf.open("data.dat");
//		if (inf.is_open()) {
//			for (Order order : order_list) {
//				inf << order.id << "\n" << order.Username << "\n" << order.description << "\n" << order.status << "\n" << order.price << "\n" << order.delete_status << "\n*\n";
//			}
//		}
//		else cout << "error: гребанный рот этого казино, блин" << endl;
//		inf.close();
//	};
//
//	vector<Order> Load() { //выгрузка заказов
//		vector<Order> order_list;
//		system("cls");
//		fstream in;
//		in.open("data.dat");
//		if (in.is_open())
//		{
//			while (!in.eof()) {
//				Order order;
//				string data;
//				bool flag = true;
//				getline(in, data);
//				if (flag) {
//					getline(in, data);
//					order.Username = data;
//					getline(in, data);
//					order.description = data;
//					getline(in, data);
//					order.status = data;
//					getline(in, data);
//					order.price = atoi(data.c_str());
//					getline(in, data);
//					order.delete_status = atoi(data.c_str());
//					getline(in, data);
//					if (order.delete_status == false)order_list.push_back(order);
//				}
//			}
//			order_list.pop_back();
//			in.close();
//			system("pause");
//		}
//		return order_list;
//	}
//
//private:
//
//};

