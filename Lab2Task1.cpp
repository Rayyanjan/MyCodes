#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Rational
{
private:
    int num, den;

public:
    // default constructor
    Rational() : num{0}, den{1}
    { /* empty */
    }
    Rational(int n) : num{n}, den{1}
    { /* empty */
    }
    Rational(int n, int d) : num{n}, den{d}
    { /* empty */
    }
    // copy constructor
    Rational(const Rational &r) : num{r.num}, den{r.den}
    { /* empty */
    }
    Rational(const string &a)
    {
        int pos = a.find('/');
        num = stoi(a.substr(0, pos));

        if (stoi(a.substr(pos + 1)) != 0)
        {
            den = stoi(a.substr(pos + 1));
        }
    }
    void printFraction()
    {
        cout << "Numerator: " << num << ", Denominator: " << den << endl;
    }
    Rational(double n){
        double rem = n - floor(n);
        int i =1 ;
        while(rem - floor(rem) != 0){
            rem *= 10;
            i *= 10;
        }
        num = static_cast<int>(rem) + floor(n)*i;
        den = i;
        reduce();
    }
    int get_num()const{
        return num;
    }
    int get_den()const{
        return den;
    }
    void set_num(int n){
        num = n;
    }
    void set_den(int d){
        den = d;
    }
    string To_string()const{
        return to_string(num)+ '/' + to_string(den);
    }
    void reduce(){
        int arr[10] = {2,3,5,7,11,13,17,19,23,29};
        int i = 0;
        while(i<10){
            if((num%arr[i]==0) && (den%arr[i]==0)){
                num /= arr[i];
                den /= arr[i];
            }
            else{
                ++i;
            }
        }
    }
    Rational operator+(const Rational& r) const {
        int common_denominator = den * r.den;
        int result_numerator = (num * r.den) + (r.num * den);
        Rational result(result_numerator, common_denominator);
        result.reduce();
    return result;
}
    Rational operator-(const Rational& r)const{
        int common_denominator = den * r.den;
        int result_numerator = (num * r.den) - (r.num * den);
        Rational result(result_numerator, common_denominator);
        result.reduce();
    return result;     
}
    Rational operator*(const Rational& r)const{
        int common_denominator = den * r.den;
        int result_numerator = (num * r.num);
        Rational result(result_numerator, common_denominator);
        result.reduce();
    return result;  
    }
    Rational operator/(const Rational& r) const {
        if (r.num == 0) {
            cerr << "Error: Division by zero." << endl;
        return Rational();
    }
        int common_denominator = den * r.num;
        int result_numerator = num * r.den;
        Rational result(result_numerator, common_denominator);
        result.reduce();
    return result;
}
    bool operator==(const Rational& r)const{
        return (num * r.den == r.num * den);
}
    bool operator!=(const Rational& r)const{
        return (num * r.den != r.num * den);
}

};
int main() {
    
    Rational r1;                 
    Rational r2(5);              
    Rational r3(3, 4);           
    Rational r4("1/2");          
    Rational r5(0.75);          

    cout << "Numerator of r1: " << r1.get_num() << endl;  
    cout << "Denominator of r3: " << r3.get_den() << endl;

    r2.set_num(7);
    r2.set_den(2);
    cout << "r2 after set_num(7) and set_den(2): " << r2.To_string() << endl; 

    cout << "String representation of r4: " << r4.To_string() << endl; 

    r3.reduce();
    cout << "r3 after reduce: " << r3.To_string() << endl; 

    Rational sum = r3 + r4;
    cout << "Sum of r3 and r4: " << sum.To_string() << endl; 

    Rational difference = r4 - r3;
    cout << "Difference of r4 and r3: " << difference.To_string() << endl; 

    Rational product = r3 * r5;
    cout << "Product of r3 and r5: " << product.To_string() << endl; 

    Rational quotient = r2 / r4;
    cout << "Quotient of r2 and r4: " << quotient.To_string() << endl; 

    cout << "Are r3 and r4 equal? " << (r3 == r4) << endl; 
    cout << "Are r2 and r5 not equal? " << (r2 != r5) << endl; 

    return 0;
}