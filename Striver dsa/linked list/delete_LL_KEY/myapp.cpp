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
    head->next->back = head; 
    head->next->next = new Node(10);
    head->next->next->back = head->next; 
    int key=10;

    //returning a new list--
    Node* temp=head;
    Node*dummy=new Node(-1);
    Node *curr=dummy;
    while(temp!=nullptr){
        if(temp->data!=key){
            Node *nw=new Node(temp->data);
            curr->next=nw;
            nw->back=curr;
            curr=curr->next;
        }
        temp=temp->next;
    }
    temp=dummy->next;
     while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"null";

}