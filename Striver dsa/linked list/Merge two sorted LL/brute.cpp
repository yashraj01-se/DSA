#include <iostream>
#include <vector>
#include<algorithm>
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
 
        vector<int>v;
        Node * temp=head1;
        while(temp!=nullptr){
             v.push_back(temp->data);
             temp=temp->next;
        }
        temp=head2;
        while(temp!=nullptr){
             v.push_back(temp->data);
             temp=temp->next;
        }

        sort(v.begin(),v.end());
        
        Node *dummy=new Node(0);
        Node *curr=dummy;
        for(int i=0;i<v.size();i++){
            Node *nw=new Node(v[i]);
            curr->next=nw;
            curr=curr->next;
        }

        Node *temp1=dummy->next;
        while(temp1!=nullptr){
         cout<<temp1->data<<"->";
         temp1=temp1->next;
        }cout<<"null";
    }