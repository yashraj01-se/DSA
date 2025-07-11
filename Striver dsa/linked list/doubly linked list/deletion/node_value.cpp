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
    cout << "Doubly linked list before value is deleted: ";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;

    int k;
    cout << "enter the value you want to delete" << endl;
    cin >> k;

    temp = head;

    while (temp!=nullptr && temp->data != k)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "Value not found in the list." << endl;
    }
    else
    {
        Node *prev = temp->back;
        Node *front = temp->next;

        if (temp->next != nullptr)
        {
            prev->next = temp->next;
            front->back = temp->back;
            delete temp;
        }
        else
        {
            prev->next = nullptr;
            delete temp;
        }
    }

    temp = head; // since temp is reassinged to the hed , we can access it...
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null";
}