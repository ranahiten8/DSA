#include <iostream>
#include "hashtable.h"
#include <cstring>
using namespace std;

int main()
{
    Hashtable<int> price_menu;
    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 25);
    price_menu.insert("Dosa", 100);
    price_menu.insert("Noodles", 150);
    price_menu.insert("Coke", 50);

    price_menu.print();
    int *price = price_menu.search("Noodles");
    if (price == NULL)
    {
        cout << "Not found";
    }
    else
    {
        cout << "Price is " << *price << endl;
    }

    price_menu.erase("Dosa");
    price_menu.print();
    cout << endl;
    price_menu["Dosa"] = 60;
    price_menu["Dosa"] += 10;
    cout <<"price of dosa "<< price_menu["Dosa"] << endl;

    return 0;
}