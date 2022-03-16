#include "User.h"

void User::setLogin(std::string& lgn) {
    login = lgn;
}
void User::setPassword(std::string& psw) {
    password = psw;
}
void User::setStatus(const int& i) {
    status = i;
}
std::string User::getLogin() {
    return login;
}
std::string User::getPassword() {
    return password;
}
int User::getStatus() {
    return status;
}