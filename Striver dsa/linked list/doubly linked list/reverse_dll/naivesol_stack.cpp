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
    Node *temp = head;
    cout << "before: ";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;

    stack<int> s;
    temp = head;
    // pushing all value in stack
    while (temp != nullptr)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    // now we are simply taking out one value from the stack and replacing it with the DLL by head;
    temp = head;
    while (temp != nullptr)
    {
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }

    cout << "after: ";
    temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null";
}