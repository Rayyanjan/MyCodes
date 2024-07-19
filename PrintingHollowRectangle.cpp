#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter a value for row: ";
    cin >> row;
    int col;
    cout << "Enter a value for col: ";
    cin >> col;

    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(i == 1 || i == row || j==1 || j==col){
               cout << "*"; 
            }
            else{
                cout << " ";
            } 
        }
        cout << endl;
    }
}