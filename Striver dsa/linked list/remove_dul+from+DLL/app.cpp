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
    Node *head = new Node(10);
    head->next = new Node(10);
    head->next->back = head; 
    head->next->next = new Node(20);
    head->next->next->back = head->next; 
    int key=10;

    Node *temp=head;
     
    while(temp!=nullptr && temp->next !=nullptr){
        Node *nexn=temp->next;
        while(nexn != nullptr && nexn->data==temp->data){
            nexn=nexn->next;
        }
        temp->next=nexn;
        if(nexn)nexn->back=temp;
        temp=temp->next;
       }

       temp=head;
        while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"null";

}