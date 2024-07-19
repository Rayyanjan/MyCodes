#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<string> visited;

    string address;
    while (cin >> address) {
        if (visited.find(address) == visited.end()) {
            cout << "\x1b[34m" << address << "\x1b[0m" << endl; 
            visited.insert(address);
        } else {
            cout << "\x1b[35m" << address << "\x1b[0m" << endl; 
        }
    }
    return 0;
}
