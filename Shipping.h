#pragma once
#ifndef SHIPPING_H
#define SHIPPING_H
#include "Operation.h"
#include <iostream>
using namespace std;

class Shipping :public Operation
{
private:
    string shippingInfo, shippingDate;
public:
    Shipping(){}
    ~Shipping(){}
    virtual void setinfo();
    virtual void display();
};

void Shipping::setinfo()
{
    cout << "Shipping Details : ";
    cin>> shippingInfo;
    cout << "Shipping Date : ";
    cin>> shippingDate;
}
void Shipping::display()
{
    cout << "\nShipping Information : " << shippingInfo;
    cout << "\nShipping Date : " << shippingDate;
}
#endif