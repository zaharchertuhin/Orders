#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class User {
private:
    std::string login;
    std::string password;
    int status = 1;

public:
    
    void setLogin(std::string& lgn);
    void setPassword(std::string& psw);
    void setStatus(const int& i);
    std::string getLogin();
    std::string getPassword();
    int getStatus();
};

