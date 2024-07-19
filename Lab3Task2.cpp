#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class LLQueue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* first = nullptr;
    int N = 0;

public:
    LLQueue() = default;

    ~LLQueue() {
        while (first != nullptr) {
            Node* second = first->next;
            delete first;
            first = second;
        }
    }

    void enqueue(int item) {
        if (first == nullptr) {
            first = new Node {item, nullptr};
        } else {
            Node* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node {item, nullptr};
        }
        ++N;
    }

    int dequeue() {
        if (first == nullptr) {
            throw std::runtime_error("Queue is empty");
        }
        int d = first->data;
        Node* temp = first;
        first = first->next;
        delete temp;
        --N;
        return d;
    }

    bool empty() {
        return first == nullptr;
    }

    int size() {
        return N;
    }
};

void rayyans_problem(int m, int n){
    LLQueue q;

    // Enqueue positions from 0 to n-1
    for (int i = 0; i < n; ++i)
        q.enqueue(i);

    cout << "Elimination order:" << endl;

    while (q.size() > 1) {
        for (int i = 0; i < m - 1; ++i) {
            int front = q.dequeue();
            q.enqueue(front);
        }
        cout << q.dequeue() << " ";
    }
    cout << "\nThe safe position is " << q.dequeue() << endl;
}
int main(){
    int n, m;

    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of m: ";
    cin >> m;

    rayyans_problem(m, n);

    return 0;
}