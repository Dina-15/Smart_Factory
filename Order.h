#pragma once
#ifndef ORDER_H
#define ORDER_H
#include "Operation.h"
#include <iostream>
using namespace std;
class Order :public Operation
{
private:
    string customerInfo, quantity, orderDate;
    size_t orderNum;
public:
    Order(){}
    ~Order(){}
    size_t getOrderNum();
    virtual void setinfo();
    virtual void display();
};

size_t Order::getOrderNum()
{
    return orderNum;
}
void Order::setinfo()
{
    cout << "Order Number : ";
    cin>>orderNum;
    cout << "Customer Information : ";
    cin>>customerInfo;
    cout << "Ordered Quantity : ";
    cin>>quantity;
    cout << "Order Date : ";
    cin>>orderDate;
}
void Order::display()
{
    cout << "\nOrder Number : "<<orderNum;
    cout << "\nCustomer Information : "<<customerInfo;
    cout << "\nOrdered Quantity : "<<quantity;
    cout << "\nOrder Date : "<<orderDate;
}
#endif