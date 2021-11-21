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

//class Order {
//private:
//    std::string Username;
//    int id = 0;
//    std::string description;
//    std::string status;
//    int price = 0;
//    bool delete_status = 1;
//
//public:
//    void setUsername(std::string& usrnm) {
//        Username = usrnm;
//    }
//    void setId(int& i) {
//        id = i;
//    }
//    void setDescription(std::string& dscrpt) {
//        description = dscrpt;
//    }
//    void setStatus(std::string& stts) {
//        status = stts;
//    }
//    void setPrice(int& pric) {
//        price = pric;
//    }
//    void setDelStatus(bool dlst) {
//        delete_status = dlst;
//    }
//    std::string getUsername() {
//        return Username;
//    }
//    int getId() {
//        return id;
//    }
//    std::string getDescription() {
//        return description;
//    }
//    std::string getStatus() {
//        return status;
//    }
//   int getPrice() {
//       return price;
//    }
//    bool getDelStatus() {
//        return delete_status;
//    }
//};
