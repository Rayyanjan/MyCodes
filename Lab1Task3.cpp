#include<iostream>
#include<vector>
using namespace std;

class Book{
private:
    string title;
    int code;
    float price;
    vector<float> grades;
public:
    Book(string t,int c,float p){
        title = t;
        code = c;
        price = p;
    }

    void review(float grd){
        grades.push_back(grd);
    }
    int getCode(){
        return code;
    }
    float getScore(){
        if(grades.empty()){
            return 0.0;
        }
        float sum = 0.0;
        for (float grade : grades) {
            sum += grade;
        }
        return sum/grades.size();
    }
    float getPrice(){
        return price;
    }
};

int main() {
    Book books[5] = {
    Book("The C++ Programming Language", 1, 60),
    Book("The Mythical Man-month", 2, 40),
    Book("The Pragmatic Programmer: Your Journey to Mastery", 3, 50),
    Book("The Art of Computer Programming", 4, 50),
    Book("C++ For Dummies", 5, 30)
    };
    books[0].review(5);
    books[0].review(4);
    books[1].review(4);
    books[2].review(2);
    books[3].review(5);
    int code;
    cout << "Enter code: ";
    cin >> code;
    for (int i = 0; i < 5; i++) {
    if (books[i].getCode() == code) {
    if (books[i].getScore() == 0) {
        cout << "The book has not been graded yet" << endl;
    } else {
        cout << "The book has score " << books[i].getScore() << " and price " <<
        books[i].getPrice() << endl;
    }
    return 0;
    }
    }
    cout << "The book does not exist" << endl;
    return 0;
}
