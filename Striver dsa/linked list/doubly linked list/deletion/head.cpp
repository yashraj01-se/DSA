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
    Node* head=new Node(5);
    head->next=new Node(10);
    head->next->next=new Node(15);

    if(head==nullptr || head->next==nullptr){
        cout<<nullptr;
    }

    Node*temp=head;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    delete temp;

    temp=head; //since temp is reassinged to the hed , we can access it...
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"null";
    

}