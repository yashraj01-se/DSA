#include<iostream>
#include<stack>
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
    head->next->next->next=new Node(20);
    
    Node* temp=head;
    Node *prev=nullptr;
    Node*front;
    while(temp!=nullptr){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }

     temp = prev;
    cout << "after: ";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
   


}