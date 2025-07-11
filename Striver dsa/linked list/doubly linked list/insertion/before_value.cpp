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
    cout << "Enter value before which you want to add" << endl;
    cin >> k;
    Node *nw = new Node(1);
    
    while(temp!=nullptr && temp->data!=k){
        temp=temp->next;
        if(temp==nullptr){
            cout<<"No such value exist in the DLL"<<endl;
            return 0;
        }
       }
        Node*prev=temp->back;
        nw->next=temp;
        temp->back=nw;
        prev->next=nw;
        nw->back=prev;
    temp = head;
    cout << "Doubly linked list after adding value: ";

    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null";
}