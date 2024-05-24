#include <iostream>
#include <stdlib.h>
#include "smartFactory.h"
#include "queueSubLList.h"
using namespace std;
smartFactory myfactory;
void addProduct()
{
    system("cls");
    int c;
    cout << "Main Menu -> Product Sequence Management -> Enter a New Product..\n";
    cout << "[1] At the End of the Production Line\n"
         << "[2] At the Beginning of the Production Line\n"
         << "[3] At a Specific Position in the Production Line\n"
         << "[0] Return to Previous Menu\n"
         << "Enter Your Selection : ";
    cin >> c;
    switch (c)
    {
    case 1:
    {
        system("cls");
        cout << "Main Menu -> Product Sequence Management -> Enter a New Product -> At the End..\n";
        myfactory.insertBack();
    }
    break;
    case 2:
    {
        system("cls");
        cout << "Main Menu -> Product Sequence Management -> Enter a New Product -> At the Beginning..\n";
        myfactory.insertFront();
    }
    break;
    case 3:
    {
        system("cls");
        cout << "Main Menu -> Product Sequence Management -> Enter a New Product -> At Position..\n";
        size_t i;
        cout << "Enter Position : ";
        cin >> i;
        myfactory.insertAt(i);
    }
    break;
    case 0:
        return;
    default:
        cout << "invalid!";
        break;
    }
}
void showProduct()
{
    size_t id;
    cout << "Main Menu -> Product Sequence Management -> Display Operations Sequence for a Product\n";
    cout << "Enter Product ID : ";
    cin >> id;
    myfactory.displayOperationsForAProduct(id);
}
void showAllProducts()
{
    cout << "Main Menu -> Display All Products";
    myfactory.displayProducts();
}
void cancelProduct()
{
    system("cls");
    int c;
    cout << "Main Menu -> Product Sequence Management -> Cancel a Product..\n";
    cout << "[1] At the End of the Production Line\n"
         << "[2] At the Beginning of the Production Line\n"
         << "[3] At a Specific Position in the Production Line\n"
         << "[0] Return to Main Menu\n"
         << "Enter Your Selection : ";
    cin >> c;
    switch (c)
    {
    case 1:
    {
        system("cls");
        cout << "Main Menu -> Product Sequence Management -> Cancel a Product -> At the End..\n";
        myfactory.removeBack();
    }
    break;
    case 2:
    {
        system("cls");
        cout << "Main Menu -> Product Sequence Management -> Cancel a Product -> At the Beginning..\n";
        myfactory.removeFront();
    }
    break;
    case 3:
    {
        system("cls");
        cout << "Main Menu -> Product Sequence Management -> Cancel a Product -> At Position..\n";
        size_t i;
        cout << "Enter Position : ";
        cin >> i;
        myfactory.removeAt(i);
    }
    break;
    case 0:
        return;
    default:
        cout << "invalid! ";
        break;
    }
}
void ProductMangement()
{
    system("cls");
    cout << "Main Menu -> Product Sequence Management\n"
         << "[1] Enter a New Product\n"
         << "[2] Display Operations Sequence for a Product\n"
         << "[3] Cancel a Product\n"
         << "[0] Return to Main Menu\n"
         << "Please, Enter Your Selection : ";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        system("cls");
        addProduct();
        system("pause");
    }
    break;
    case 2:
    {
        system("cls");
        showProduct();
        system("pause");
    }
    break;
    case 3:
        system("cls");
        cancelProduct();
        system("pause");
        break;
    case 0:
        break;
    default:
        cout << "invaild !";
        system("pause");
    }
}
void addOperation()
{
}

int main()
{
    int ch;
    while (ch != 0)
    {
        system("cls");
        cout << "Main Menu\n==========\n"
             << "[1] Product Sequence Management \n"
             << "[2] Excute Manufacturing Process\n"
             << "[3] Report Production Line\n"
             << "[4] Help and Support\n"
             << "Please, Enter Your Selection : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            system("cls");
            ProductMangement();
        }
        break;
        case 2:
        {
            system("cls");
            myfactory.execute();
            system("pause");
        }
        break;
        case 3:
        {
            system("cls");
            showAllProducts();
            system("pause");
        }
        break;
        case 4:
            system("cls");
            cout << "Call Me On 01284735587\nBests Dina \x03 \n";
            system("pause");
            break;
        case 0:
            break;
        default:
            cout << "invaild !";
            system("pause");
        }
    }
    return 0;
}