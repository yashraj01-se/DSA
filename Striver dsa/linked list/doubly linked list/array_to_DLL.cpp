#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node * back;

    public:
    Node(int val,Node* next1,Node*back1){
        data=val;
        next=next1;
        back=back1;
    }
    Node(int val){
        data=val;
        next=nullptr;
        back=nullptr;
    }
};
int main(){
    int arr[5]={1,2,3,4,5};
    Node *head=new Node(arr[0]);
    Node*temp=head;
    int i=1;
    int n=sizeof(arr)/sizeof(arr[0]);
   for(int i=1;i<n;i++){
     Node *nw=new Node(arr[i]);
     temp->next=nw;
     nw->back=temp;
     temp=temp->next;
   }
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"null";
}