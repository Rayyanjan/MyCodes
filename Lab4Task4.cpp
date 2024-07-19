#include<iostream>
#include<vector>
using namespace std;

class animal{
    protected:
    string species;
    int age;
    public:
    animal(string s, int a){
        species = s;
        age = a;
    }
    void printdetails(){
        cout << "Species: " << species << endl << "Age: " << age << endl;
    }
    string getspecies(){
        return species;
    }
    void setspecies(string st){
        species = st;
    }
    void setspecies(int x){
        age = x;
    }
    int getage(){
        return age;
    }
};
class dog : public animal{
    private:
    char gender;
    int height;
    public:
    dog(string s, int a, char g, int h): animal(s, a),gender(g),height(h){}
    char getgender(){
        return gender;
    }
    void setgender(char x){
        if(gender == 'M' || gender == 'F'){
           gender = x;
        }
        else{
            cout << "Not a valid gender!";
        }
    }
    int getheight(){
        return height;
    }
    void setheight(int h){
        height = h;
    }
    void printdetails(){
        cout << "Gender: " << gender << endl <<"Height: " << height << endl;
    }
};

class cat : public animal{
    private:
    char gender;
    int height;
    public:
    cat(string s, int a, char g, int h): animal(s, a),gender(g),height(h){}
    char getgender(){
        return gender;
    }
    void setgender(char x){
        if(gender == 'M' || gender == 'F'){
           gender = x;
        }
        else{
            cout << "Not a valid gender!";
        }
    }
    int getheight(){
        return height;
    }
    void setheight(int h){
        height = h;
    }
    void printdetails(){
        cout << "Gender: " << gender << endl <<"Height: " << height << endl;
    }
};

class hamster : public animal{
    private:
    char gender;
    int height;
    public:
    hamster(string s, int a, char g, int h): animal(s, a),gender(g),height(h){}
    char getgender(){
        return gender;
    }
    void setgender(char x){
        if(gender == 'M' || gender == 'F'){
           gender = x;
        }
        else{
            cout << "Not a valid gender!";
        }
    }
    int getheight(){
        return height;
    }
    void setheight(int h){
        height = h;
    }
    void printdetails(){
        cout << "Gender: " << gender << endl <<"Height: " << height << endl;
    }
};

class tiger : public animal{
    private:
    char gender;
    int height;
    public:
    tiger(string s, int a, char g, int h): animal(s, a),gender(g),height(h){}
    char getgender(){
        return gender;
    }
    void setgender(char x){
        if(gender == 'M' || gender == 'F'){
           gender = x;
        }
        else{
            cout << "Not a valid gender!";
        }
    }
    int getheight(){
        return height;
    }
    void setheight(int h){
        height = h;
    }
    void printdetails(){
        cout << "Gender: " << gender << endl <<"Height: " << height << endl;
    }
};

class additional{
    private:
    vector<animal*>all;
    public:
    void addobject(animal* ptr){
        all.push_back(ptr);
    }
    void printall(){
        for(animal* i:all){
            i -> printdetails();
        }
    }
};

int main(){
    dog d("Mammal",10,'M',90);
    cat c("Mammal",5,'F',20);
    hamster h("Mammal",2,'M',34);
    tiger t("Mammal",15,'F',46);
    cout<<"Details for a dog are: ";
    d.printdetails();
    d.setgender('F');
    cout<<"\nNow Gender is changed to "<<d.getgender() << endl;
    additional x;
    x.addobject(&d);
    x.addobject(&c);
    x.addobject(&h);
    x.addobject(&t);
    x.printall();
}