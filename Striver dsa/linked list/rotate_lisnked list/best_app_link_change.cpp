#include <iostream>
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

int length(Node *head){
    Node*temp=head;
    int count=0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}
int main()
{
    Node *y = new Node(2);
    y->next = new Node(3);
    y->next->next = new Node(4);
    y->next->next->next=new Node(5);
    y->next->next->next->next=new Node(6);

   Node *temp1=y;
   Node* temp2=y;
   
   int len=length(y);
   int k=2;
   k=k%len;
   int diff=len-k;

   while(temp1->next!=nullptr){
      temp1=temp1->next;
   }
   temp1->next=y;

   while(diff>1){
    diff--;
    temp2=temp2->next;
   }
   y=temp2->next;
   temp2->next=nullptr;

  
   while(y!=nullptr){
    cout<<y->data<<"->";
    y=y->next;
   }cout<<"null";


}