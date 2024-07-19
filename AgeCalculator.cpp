#include<iostream>
using namespace std;

int main(){
    int age;
    cout << "Enter age: ";
    cin >> age;

        if(age < 12){
            cout << "You are a child.";
        }
        else if(age >= 12 && age <=18){
            cout << "You are a teenager.";
        }
        else{
            cout << "You are an adult.";
        }
}