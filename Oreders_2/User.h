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

public: //ну ты понял
    
    void setLogin(std::string& lgn) {
        login = lgn;
    }
    void setPassword(std::string& psw) {
        password = psw;
    }
    void setStatus(const int& i) {
        status = i;
    }
    std::string getLogin() {
        return login;
    }
    std::string getPassword() {
        return password;
    }
    int getStatus() {
        return status;
    }
};

