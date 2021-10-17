#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>



struct Order {
    std::string Username;
    int id = NULL;
    std::string description;
    std::string status;
    int price = 0;
    bool delete_status = 1;
};

