#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


class Order {
private:
    std::string Username;
    int id ;
    std::string description;
    std::string status;
    int price;
    bool delete_status;

public:

    void setUsername(std::string& usrnm) {
        Username = usrnm;
    }
    void setId(int& i) {
        id = i;
    }
    void setDescription(std::string& dscrpt) {
        description = dscrpt;
    }
    void setStatus(std::string& stts) {
        status = stts;
    }
    void setPrice(int& pric) {
        price = pric;
    }
    void setDelStatus(bool dlst) {
        delete_status = dlst;
    }
    std::string getUsername() {
        return Username;
    }
    int getId() {
        return id;
    }
    std::string getDescription() {
        return description;
    }
    std::string getStatus() {
        return status;
    }
   int getPrice() {
       return price;
    }
    bool getDelStatus() {
        return delete_status;
    }
};



