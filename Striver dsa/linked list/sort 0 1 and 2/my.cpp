#include <iostream>
#include <stack>
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
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(0);
    head->next->next->next->next=new Node(2);
    head->next->next->next->next->next=new Node(1);

     Node *temp = head;
    cout << "before: ";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;

    temp=head;
    int zero_count=0;
    int one_count=0;
    int two_count=0;
    while(temp!=nullptr){
        if(temp->data==0){
            zero_count++;
            temp=temp->next;
        }
        else if(temp->data==1){
            one_count++;
            temp=temp->next;
        }
        else{
            two_count++;
            temp=temp->next;
        }
    }
    temp=head;
    while (temp!=nullptr)
    {
       while(zero_count>0){
        temp->data=0;
        temp=temp->next;
        zero_count--;
       }
       while(one_count>0){
        temp->data=1;
        temp=temp->next;
        one_count--;
       }
        while(two_count>0){
        temp->data=2;
        temp=temp->next;
        two_count--;
       }
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