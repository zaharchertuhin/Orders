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
};
