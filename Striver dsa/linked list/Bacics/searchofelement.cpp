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
     int ele;
     cout<<"enter the number to search"<<endl;
     cin>>ele;
     bool flag=false;
     int index=0;
     while(temp!=nullptr){
        if(temp->data==ele){
            flag=true;
            break;
        }
        temp=temp->next;
        index++;
     }
     if(flag){
        cout<<"Number is found at position: "<<index;
     }
     else{
    cout<<"No such number";
     }

}