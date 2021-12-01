#include "Order.h"

void Order::setUsername(std::string& usrnm) {
        Username = usrnm;
    }
    void Order::setId(int& i) {
        id = i;
    }
    void Order::setDescription(std::string& dscrpt) {
        description = dscrpt;
    }
    void Order::setStatus(std::string& stts) {
        status = stts;
    }
    void Order::setPrice(int& pric) {
        price = pric;
    }
    void Order::setDelStatus(bool dlst) {
        delete_status = dlst;
    }
    std::string Order::getUsername() {
        return Username;
    }
    int Order::getId() {
        return id;
    }
    std::string Order::getDescription() {
        return description;
    }
    std::string Order::getStatus() {
        return status;
    }
   int Order::getPrice() {
       return price;
    }
    bool Order::getDelStatus() {
        return delete_status;
    }