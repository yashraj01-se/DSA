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

    cout << "linked list before deletion of head:";
    Node *temp = y;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null"<<endl;;

    if(y==nullptr)cout<<y;

    cout << "linked list after deletion of head:";
    temp = y;

    y = y->next;
    delete temp;

    Node *temp1 = y;
    while (temp1 != nullptr)
    {
        cout << temp1->data << "->";
        temp1= temp1->next;
    }
    cout << "null";
}