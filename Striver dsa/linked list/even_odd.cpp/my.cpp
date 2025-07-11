#include <iostream>
#include <stack>
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
    head->next->next = new Node(15);
    head->next->next->next = new Node(20);
    Node *temp = head;
    cout << "before: ";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;

    temp=head;

    Node *temp_odd = head;
    Node *dummy = new Node(-1);
    Node *curr = dummy;
    Node *temp_even = head->next;
    while (temp_odd)
    {
        curr->next = new Node(temp_odd->data);
        curr = curr->next;
        if (temp_odd->next && temp_odd->next->next)
            temp_odd = temp_odd->next->next;
        else
        {
            temp_odd = nullptr;
        }
    }
    while (temp_even)
    {
        curr->next = new Node(temp_even->data);
        curr = curr->next;
        if (temp_even->next && temp_even->next->next)
            temp_even = temp_even->next->next;
        else
        {
            temp_even = nullptr;
        }
    }
    cout<<"after: ";
    temp = dummy->next;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null";
}