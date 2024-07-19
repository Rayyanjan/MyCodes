#include <iostream>


using namespace std;

class Polynomial {
private:
    int a;
    int b;
    int c;

public:
    Polynomial() : a(1), b(1), c(1) {}
    Polynomial(int a, int b, int c) : a(a), b(b), c(c) {}

    string format() const {
        return to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c);
    }

    int eval(int x) const {
        return a * x * x + b * x + c;
    }

    Polynomial operator+(const Polynomial& other) const {
        return Polynomial(a + other.a, b + other.b, c + other.c);
    }

    int& operator[](int index) {
        if (index == 0) {
            return a;
        } else if (index == 1) {
            return b;
        } else if (index == 2) {
            return c;
        } else {
            cerr << "Invalid index. Exiting program." << endl;
            exit(EXIT_FAILURE);
        }
    }

    bool operator==(auto other) const {
        return (a == other.a) && (b == other.b) && (c == other.c);
    }
};

int main() {
    Polynomial poly1;
    Polynomial poly2(2, -3, 1);

    cout << "Polynomial 1: " << poly1.format() << endl;
    cout << "Polynomial 2: " << poly2.format() << endl;

    cout << "Evaluation of Polynomial 1 at x=3: " << poly1.eval(3) << endl;
    cout << "Evaluation of Polynomial 2 at x=3: " << poly2.eval(3) << endl;

    Polynomial sum = poly1 + poly2;
    cout << "Sum of Polynomials: " << sum.format() << endl;

    poly1[0] = 3;
    poly1[1] = 5;
    poly1[2] = 7;

    cout << "Modified Polynomial 1: " << poly1.format() << endl;

    if (poly1 == poly2) {
        cout << "Polynomials are equal." << endl;
    } else {
        cout << "Polynomials are not equal." << endl;
    }

    return 0;
}
