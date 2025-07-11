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

    temp = head; // since temp is reassinged to the hed , we can access it...
    cout << "Doubly linked list before kth postion deleted: ";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;

    int k;
    cout << "enter the position you want to delete" << endl;
    cin >> k;
    int count = 1;

    temp = head;

    if (k <= 0)
    {
        cout << "invalid position." << endl;
    }
    else
    {

        if (k == 1)
        {
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }
        else
        {

            while (count < k && temp != nullptr)
            {
                temp = temp->next;
                count++;
            }
            if (temp == nullptr)
            {
                cout << "Position out of range." << endl;
                return 0;
            }
            Node *prev = temp->back;
            Node *after = temp->next;
            prev->next = temp->next;
            if (after != nullptr)
                after->back = temp->back;
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
