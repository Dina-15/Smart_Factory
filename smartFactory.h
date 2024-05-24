#pragma once
#ifndef SMARTFACTORY_H
#define SMARTFACTORY_H
#include <unistd.h>
#include "queueSubLList.h"
#include "Stack.h"
#include "Product.h"
#include "Operation.h"
#include "Order.h"
#include "Shipping.h"
class smartFactory
{
private:
    queueSubLList<Product *> list;

public:
    smartFactory() {}
    ~smartFactory() {}
    void displayProducts();
    void displayOperationsForAProduct(size_t id);
    void insertBack();
    void insertFront();
    void insertAt(size_t index);
    void removeFront();
    void removeBack();
    void removeAt(size_t index);
    void execute();
};
#endif
void smartFactory::displayProducts()
{
    Product *currProduct;
    for (int i = 0; i < list.getCount(); i++)
    {
        currProduct = list.get(i);
        cout << "\nProduct Information..\n";
        cout << currProduct;
        cout << "\n-----------------"
             << "\nOperations Sequence...\n";
        for (int j = 0; j < currProduct->getSize() - 2; j++)
        {
            Operation *op = currProduct->get(j);
            op->display();
            cout << "\n";
        }
        cout << "\nOrder Information..\n";
        Operation *op = currProduct->get(currProduct->getSize() - 2);
        op->display();
        cout << "\n-----------------"
             << "\nShipping Information..\n";
        Operation *ope = currProduct->get(currProduct->getSize() - 1);
        ope->display();
        cout << "\n================================\n";
    }
}
void smartFactory::displayOperationsForAProduct(size_t id)
{
    Product *p;
    p = list.find(id);
    cout << p;
    cout << "\n-------------\n";
    Operation *op;
    for (int j = 0; j < p->getSize() - 2; j++)
    {
        op = p->get(j);
        op->display();
        cout<<"\n";
    }
    op = p->get(p->getSize()-2);
    op->display();
    op = p->get(p->getSize()-1);
    op->display();
    cout << "\n";
}
void smartFactory::insertBack()
{
    Product *p = new Product();
    cout << "\nProduct Information..\n";
    cin >> p;
    cout << "-----------------"
         << "\nOperations Sequence...\n";
    Operation *op;
    char c = 'y';
    while (c == 'Y' || c == 'y')
    {
        op = new Operation();
        op->setinfo();
        p->pushBack(op);
        cout << "Another Operation (y/n) : ";
        cin >> c;
    }
    cout << "-----------------"
         << "\nOrder Information..\n";
    op = new Order();
    op->setinfo();
    p->pushBack(op);
    cout << "-----------------"
         << "\nShipping Information..\n";
    op = new Shipping();
    op->setinfo();
    p->pushBack(op);
    list.pushBack(p);
}
void smartFactory::insertFront()
{
    Product *p = new Product();
    cout << "\nProduct Information..\n";
    cin >> p;
    cout << "-----------------"
         << "\nOperations Sequence...\n";
    Operation *op;
    char c = 'y';
    while (c == 'Y' || c == 'y')
    {
        op = new Operation();
        op->setinfo();
        p->pushBack(op);
        cout << "Another Operation (y/n) : ";
        cin >> c;
    }
    cout << "-----------------"
         << "\nOrder Information..\n";
    op = new Order();
    op->setinfo();
    p->pushBack(op);
    cout << "-----------------"
         << "\nShipping Information..\n";
    op = new Shipping();
    op->setinfo();
    p->pushBack(op);
    list.pushFront(p);
}
void smartFactory::insertAt(size_t index)
{
    Product *p = new Product();
    cout << "\nProduct Information..\n";
    cin >> p;
    cout << "-----------------"
         << "\nOperations Sequence...\n";
    Operation *op;
    char c = 'y';
    while (c == 'Y' || c == 'y')
    {
        op = new Operation();
        op->setinfo();
        p->pushBack(op);
        cout << "Another Operation (y/n) : ";
        cin >> c;
    }
    cout << "-----------------"
         << "\nOrder Information..\n";
    op = new Order();
    op->setinfo();
    p->pushBack(op);
    cout << "-----------------"
         << "\nShipping Information..\n";
    op = new Shipping();
    op->setinfo();
    p->pushBack(op);
    list.pushAt(index, p);
}
void smartFactory::removeFront()
{
    cout << list.popFront();
}
void smartFactory::removeBack()
{
    cout << list.popBack();
}
void smartFactory::removeAt(size_t index)
{
    cout << list.popAt(index);
}
void smartFactory::execute()
{
    Product *currProduct;
    for (int i = 0; i < list.getCount(); i++)
    {
        currProduct = list.get(i);
        cout << "\nProduct " << currProduct->getName() << " ...";
        size_t s = currProduct->getSize() - 2;
        for (int j = 0; j < s; j++)
        {
            Operation *op = currProduct->Front();
            cout << "\nOperation " << op->getName() << " In Progress ..";
            currProduct->popFront();
            delete op;
            sleep(2);
        }
        Operation *op = currProduct->Front();
        currProduct->popFront();
        cout << "\nOrder Completed ..";
        delete op;
        sleep(2);
        Operation *ope = currProduct->Front();
        currProduct->popFront();
        cout << "\nProduct Shipped Successfully..";
        delete ope;
        delete currProduct;
        cout << "\n=====================\n";
    }
}