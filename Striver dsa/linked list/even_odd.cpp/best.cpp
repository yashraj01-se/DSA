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
    head->next->next->next->next=new Node(30);
    head->next->next->next->next->next=new Node(40);
    Node *temp = head;
    cout << "before: ";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;

    Node* temp_odd=head;
        if(head==nullptr || head->next==nullptr){
            cout<<head;
        }
        Node* temp_even=head->next;
        Node* even_head=head->next;

        while(temp_even!=nullptr && temp_even->next!=nullptr){
           temp_odd->next=temp_odd->next->next;
           temp_even->next=temp_even->next->next;

           temp_odd=temp_odd->next;
           temp_even=temp_even->next;
        }
        temp_odd->next=even_head;
       
        temp=head;

        cout<<"after: ";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null";

}