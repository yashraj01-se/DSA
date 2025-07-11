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
    int key=5;

    Node *temp=head;
    while(temp!=nullptr){
        if(temp->data==key){
            if(temp==head){
                head=head->next;
            }
            Node* prevnode=temp->back;
            Node* nextnode=temp->next;
            if(nextnode)nextnode->back=prevnode;
            if(prevnode)prevnode->next=nextnode;
            delete(temp);
            temp=nextnode;
        }
        else{
            temp=temp->next;
        }

    }
     temp=head;

         while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"null";

}