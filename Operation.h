#pragma once
#ifndef OPERATION_H
#define OPERATION_H
#include <iostream>
#include <string>
using namespace std;

class Operation
{
private:
    string name;
public:
    Operation() {}
    ~Operation() {}
    string getName();
    bool find(string key);
    virtual void setinfo();
    virtual void display();
};
#endif
string Operation::getName()
{
    return name;
}
bool Operation::find(string key)
{
    if(name == key)
        return true;
    else
        return false;
}
void Operation::setinfo()
{
    cout << "Operation Name : ";
    cin>>name;
}
void Operation::display()
{
    cout << "Operation Name : " << name;
}

