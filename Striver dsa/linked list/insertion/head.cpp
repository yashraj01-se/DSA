#include <iostream>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

int main()
{
    Node *y = new Node(2);
    y->next = new Node(3);
    y->next->next = new Node(4);

    cout << "linked list before insertion of value at head:";
    Node *temp = y;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null"<<endl;

    Node *temp1=new Node(5);
    temp1->next=y;
    y=temp1;

    cout << "linked list after insertion of value at head:";

    Node *temp2=y;
     while (temp2 != nullptr)
    {
        cout << temp2->data << "->";
        temp2= temp2->next;
    }
    cout << "null";
}