#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class WareHouse {
private:
    vector<int> codes;
    vector<int> quantities;

public:
    WareHouse() {
    }

    void stock(int c, int q) {
        auto check = find(codes.begin(), codes.end(), c);

        if (check != codes.end()) {
            int index = distance(codes.begin(), check);
            quantities[index] += q;
            cout << q << " items with code " << c << " added. Total: " << quantities[index] << endl;
        } else {
            codes.push_back(c);
            quantities.push_back(q);
            cout << q << " items with code " << c << " added." << endl;
        }
    }

    void order(int c, int q) {
        auto check = find(codes.begin(), codes.end(), c);

        if (check == codes.end()) {
            cout << "The requested quantity is not available." << endl;
        } else {
            int index = distance(codes.begin(), check);
            if (quantities[index] >= q) {
                quantities[index] -= q;
                cout << q << " items delivered with code " << c << endl;
            } else {
                cout << "The requested quantity is not available." << endl;
            }
        }
    }

    void show(int c) {
        auto check = find(codes.begin(), codes.end(), c);

        if (check == codes.end()) {
            cout << "Code " << c << " not found." << endl;
        } else {
            int index = distance(codes.begin(), check);
            cout << quantities[index] << " items are stored with code " << c << endl;
        }
    }
};

int main() {
    WareHouse w;
    w.stock(1, 10); // print "10 items with code 1 added"
    w.stock(2, 20); // print "20 items with code 2 added"
    w.stock(3, 30); // print "30 items with code 3 added"
    w.stock(1, 5); // print "5 more items with code 1 added, total 15"
    w.order(1, 3); // print "3 items delivered with code 1"
    w.order(2, 25); // print "the requested quantity is not available"
    w.order(2, 11); // print "11 items delivered with code 2"
    w.order(4, 5); // print "Code 4 not found"
    w.show(1); // print "12 items are stored with code 1"
    w.show(2); // print "9 items are stored with code 2"
    w.show(3); // print "30 items are stored with code 3"
    w.show(4); // print "Code 4 not found"

    return 0;
}
