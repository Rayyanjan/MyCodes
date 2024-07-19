#include<iostream>
using namespace std;

class SafeArray{
    private:
    int size;
    int* array;

    public:
    SafeArray(int sz) {
       this->size = sz;
       array = new int[size];  // Allocate memory for the array
       for (int i = 0; i < sz; i++) {
           array[i] = 0;  // Initialize all elements to 0
       }
    }






};