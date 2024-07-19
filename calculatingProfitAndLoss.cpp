#include<iostream>
using namespace std;

int main(){
    int costprice, sellingprice;
    cout << "Enter cost price: " << endl;
    cin >> costprice;
    cout << "Enter selling price: " << endl;
    cin >> sellingprice;

    if (costprice > sellingprice){
        int loss = costprice - sellingprice;
        cout << "Loss is " << loss ;
    }
    else{
        int profit = sellingprice - costprice;
        cout << "profit is " << profit ;
    }

    
}