#include<iostream>
using namespace std;

class Student {
    private:
        int erpID;
        string name;
        float cgpa;
    public:
        Student(int id, string n, float c) { // constructor
        erpID = id;
        name = n;
        cgpa = c;
}
    void setCGPA(float c) { // setter
        cgpa = c;
}
    int getErpID() { // getter
        return erpID;
}
    string getName() { // getter
        return name;
}
    float getCGPA() { // getter
        return cgpa;
}
};

class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date(int dd, int mm, int yy){
            day = dd;
            if(mm > 12 || mm <1){mm = 1;}
            month = mm;
            year = yy;
        }
        void setday(int d){
            day = d;
        }
        void setmonth(int m){
            month = m;
        }
        void setyear(int y){
            year = y;
        }
        string formatdate(){
            string s1= to_string(day); 
            string s2= to_string(month);
            string s3= to_string(year);
            string s4= s1 + '/' + s2 + '/' + s3;
            return s4;
        }
        
};

int main(){
    Date d1(19, 1, 2024);
    cout << d1.formatdate() << endl; // should print 19/1/2024
    d1.setday(17);
    cout << d1.formatdate() << endl; // should print 17/1/2024
    d1.setmonth(5);
    cout << d1.formatdate() << endl; // should print 17/5/2024
    Date d2(29, 13, 2024); // should set month to 1
    cout << d2.formatdate() << endl; // should print 29/1/2024
}
