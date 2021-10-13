//#ifndef CUSTOMER_H
//#define CUSTOMER_H
#include <iostream>

class Customer{
public:
    Customer() = delete;
    Customer( std::string &Name, std::string &Address);
    ~Customer() {}
    void SetStatus();
    void AddService();
private:
    unsigned int Counter = 0;
    std::string Name = "No Name";
    std::string Address = "No Address";
};
//#endif /*CUSTOMER_H*/