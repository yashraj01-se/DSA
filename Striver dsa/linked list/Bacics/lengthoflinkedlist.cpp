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
     int count=0;
     while(temp!=nullptr){
         count++;
         temp=temp->next;
     }
    cout<<count;
     
}