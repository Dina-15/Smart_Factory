#pragma once
#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_INCLUDED
#include <iostream>
#include <string>
#include "Stack.h"
#include "Operation.h"
using namespace std;
class Product : public Stack<Operation *>
{
private:
    string name, date;
    size_t id;

public:
    Product() : Stack<Operation *>() {}
    ~Product() {}
    string getName();
    bool find(size_t id);
    friend istream &operator>>(istream &in, Product *p);
    friend ostream &operator<<(ostream &out, const Product *p);
};
#endif
bool Product::find(size_t id)
{
    if (id == this->id)
        return true;
    else
        return false;
}
string Product::getName()
{
    return name;
}
istream &operator>>(istream &in, Product *p)
{
    cout << "PRODUCT ID : ";
    in >> p->id;
    cout << "PRODUCT NAME : ";
    in >> p->name;
    cout << "PRODUCT Date : ";
    in >> p->date;
    return in;
}
ostream &operator<<(ostream &out, const Product *p)
{
    out << "\nPRODUCT ID : " << p->id;
    out << "\nPRODUCT NAME : " << p->name;
    out << "\nPRODUCT Date : " << p->date;
    return out;
}
