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

    cout << "linked list before insertion of value at tail:";
    Node *temp = y;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;

    int k = 1;
    Node *nw = new Node(5);
    cout << "Enter the position you want:" << endl;
    int pos;
    cin >> pos;
    Node *temp1 = y;
    Node *temp2 = y;
    if (pos == 1)
    {
        nw->next=y;
        y=nw;

    }

    else
    {
        while (k < pos && temp1 != nullptr)
        {
            temp1 = temp1->next;
            k++;
        }
        while (temp2->next != temp1)
        {
            temp2 = temp2->next;
        }
        temp2->next = nw;
        nw->next = temp1;
    }
    cout << "linked list after insertion of value at your position:";
    temp2 = y;
    while (temp2 != nullptr)
    {
        cout << temp2->data << "->";
        temp2 = temp2->next;
    }
    cout << "null";
}