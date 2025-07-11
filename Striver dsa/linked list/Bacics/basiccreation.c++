#include<iostream>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int val){
        data=val;
        next=nullptr;
    }
};

int main(){
     Node * y=new Node(2);
     y->next=new Node(3);
     y->next->next=new Node(4);
   
     Node* temp=y;
     while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
     }cout<<"null";

}