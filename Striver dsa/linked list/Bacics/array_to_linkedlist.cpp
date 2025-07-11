#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

public: // if not decracled.constructor will be private and we cant create the object outside that class...
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
int main()
{
    int arr[4] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
     }cout<<"null";
     return 0;
}