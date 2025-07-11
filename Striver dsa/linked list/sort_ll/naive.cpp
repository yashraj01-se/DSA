#include <algorithm>
#include <vector>
#include <iostream>
#include<queue>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

int length(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int main()
{    //reusing the given linked list....
    Node *head1 = new Node(3);
    head1->next = new Node(2);
    head1->next->next = new Node(1);
    head1->next->next->next = new Node(5);
    head1->next->next->next->next = new Node(9);

    vector<int>v;
        Node* temp=head1;
        while(temp!=nullptr){
            v.push_back(temp->data);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        temp=head1;
        
       if(!v.empty()){
          temp->data=v[0];
          temp=temp->next;
       }
       int i=1;
       while(temp!=nullptr){
           temp->data=v[i];
           temp=temp->next;
           i++;
       }
       temp=head1;
       while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
       }cout<<"null";
}