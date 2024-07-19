#include<iostream>
#include<string>
using namespace std;

class binary{
private:
    string s;
public:
void read(void){
    cout << "Enter a binary number: " << endl;
    cin >> s;
}
void chk_bin(void){
    for(int i=0;i<s.length();i++){
        if(s.at(i)!= '0' && s.at(i)!= '1'){
            cout << "Wrong binary number";
            break;
        }
    }
}
void ones_comp(void){
    for(int i=0;i<s.length();i++){
        if(s.at(i)=='0'){
            s.at(i)= '1';
        }
        else{
            s.at(i)= '0';
    }
}
}
void display(void){
    for(int i=0;i<s.length();i++){
        cout << s.at(i);
    }
}
};

int main(){
    binary b;
    b.read();
    b.chk_bin();
    b.ones_comp();
    b.display();
}