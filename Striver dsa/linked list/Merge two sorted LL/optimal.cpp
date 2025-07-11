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
Node *reverseList(Node* second)
{
    Node *prev = nullptr;
    Node *temp = second;
    Node *front;
    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
    int main()
    {
        Node *head1 = new Node(2);
        head1->next = new Node(5);
        head1->next->next = new Node(8);
        head1->next->next->next = new Node(10);
        
        Node *head2=new Node(1);
        head2->next = new Node(3);
        head2->next->next = new Node(3);
        head2->next->next->next = new Node(6);
        head2->next->next->next->next=new Node(11);
        head2->next->next->next->next->next=new Node(14);

        Node*dummy=new Node(-1);
        Node* curr=dummy;
        Node*temp1=head1;
        Node*temp2=head2;
        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->data>temp2->data){
               curr->next=temp2;
                temp2=temp2->next;
                curr=curr->next;
            }
            else{
               curr->next=temp1;
                temp1=temp1->next;
                curr=curr->next;
            }
        }
        while(temp1!=nullptr){
            curr->next=temp1;
            temp1=temp1->next;
            curr=curr->next;
        }
        while(temp2!=nullptr){
            curr->next=temp2;
            temp2=temp2->next;
            curr=curr->next;
        }
        dummy=dummy->next;
        while(dummy!=nullptr){
       cout<<dummy->data<<"->";
       dummy=dummy->next;
        }cout<<"null";
    }