#include<iostream>
using namespace std;

class node{
    public:
    int value;
    node* next;

    node(int data){
        value = data;
        next = NULL;
    }
    };
    void insertAtHead(node* &head, int value){
        node* new_node = new node(value);
        new_node->next = head;
        head = new_node;
    }
    void insertAtLast(node* &head, int value){
        node* new_node = new node(value);
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    void display(node* head){
        node* temp = head;
        while(temp != NULL){
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void insertAtPos(node* &head, int value, int pos){
        if(pos==0){
            insertAtHead(head, value);
            return;
        }
        node* new_node = new node(value);
        node* temp = head;
        int curr_pos = 0;
        while(curr_pos != pos-1){
            temp = temp->next;
            curr_pos++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    int main(){
    node* head = NULL;
    insertAtHead(head ,2);
    display(head);
    insertAtHead(head, 1);
    display(head);
    insertAtLast(head, 4);
    display(head);
    insertAtPos(head, 3,1);
    display(head);
}