#pragma once
#include <string>


struct Order {
    int id;
    std::string description;
    std::string status;
    bool delete_status;
};

