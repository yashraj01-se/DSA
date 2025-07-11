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
     stack<int>st;
    Node* temp=head;
    cout << "before: ";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;

    temp = head;
    while(temp!=nullptr){
           st.push(temp->data);
           temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
          temp->data=st.top();
          st.pop();
          temp=temp->next;
    }
    
     temp = head;
    cout << "after: ";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
    

}