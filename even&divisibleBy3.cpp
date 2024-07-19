#include<iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter num which is even and divisible by 3: ";
    cin >> num;

        if((num%2 == 0) && (num%3 == 0)){
            cout << num;
        }
        else{
            cout << "Wrong input";
        }
}