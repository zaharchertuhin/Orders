#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Order {
private:
    std::string Username;
    int id = 0;
    std::string description;
    std::string status;
    int price = 0;
    bool delete_status = true;

public:
    void setUsername(std::string& usrnm);
    void setId(int& i);
    void setDescription(std::string& dscrpt);
    void setStatus(std::string& stts);
    void setPrice(int& pric);
    void setDelStatus(bool dlst);
    std::string getUsername();
    int getId();
    std::string getDescription();
    std::string getStatus();
    int getPrice();
    bool getDelStatus();
};




