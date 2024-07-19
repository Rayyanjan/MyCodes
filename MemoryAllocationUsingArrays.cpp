#include <iostream>
using namespace std;

class shop
{
    int itemid[100];
    int itemprice[100];
    int counter = 1;

public:
    void setprice()
    {
        cout << "Enter Id of your item " << counter << endl;
        cin >> itemid[counter];
        cout << "Enter price of your item " << counter << endl;
        cin >> itemprice[counter];
        counter++;
    }
    void displayprice()
    {
        for (int i = 1; i < counter; i++)
        {
            cout << "The price of item with id " << itemid[i] << " is " << itemprice[i] << endl;
        }
    }
};

int main()
{
    shop jans;
    jans.setprice();
    jans.setprice();
    jans.setprice();
    jans.setprice();
    jans.displayprice();
}