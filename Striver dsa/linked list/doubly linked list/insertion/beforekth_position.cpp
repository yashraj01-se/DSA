#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int val, Node *next1, Node *back1)
    {
        data = val;
        next = next1;
        back = back1;
    }
    Node(int val)
    {
        data = val;
        next = nullptr;
        back = nullptr;
    }
};
int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->back = head;
    head->next->next = new Node(15);
    head->next->next->back = head->next;

    Node *temp = head;
    cout << "Doubly linked list before adding value at before tail: ";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;

    temp = head;

    int k;
    int count=1;
    cout << "Enter the where you wnat to add" << endl;
    cin >> k;
    Node *nw = new Node(1);
    if(k<=0){
        cout<<"Invalid";
        return 0;
    }
    if (k == 1)
    {
        nw->next = temp;
        temp->back = nw;
        head = nw;
    }
    else{
        while(temp!=nullptr && count<k){
            temp=temp->next;
            if(temp==nullptr){
                cout<<"out of range";
                return 0;
            }
            count++;
           }
        Node* prev=temp->back;
        nw->next=temp;
        temp->back=nw;
        prev->next=nw;
        nw->back=prev;
    }

    temp = head;
    cout << "Doubly linked list after adding value before tail: ";

    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null";
}