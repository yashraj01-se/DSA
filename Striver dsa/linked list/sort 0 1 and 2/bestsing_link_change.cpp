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
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);

    Node *temp = head;
    cout << "before: ";
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;

    temp = head;

    Node *dummy_zero = new Node(-1);
    Node *curr_zero = dummy_zero;
    Node *dummy_one = new Node(-1);
    Node *curr_one = dummy_one;
    Node *dummy_two = new Node(-1);
    Node *curr_two = dummy_two;

    while (temp != nullptr)
    {
               
        if (temp->data == 0)
        {
            curr_zero->next = temp;
            curr_zero = curr_zero->next;
        }
        else if (temp->data == 1)
        {
            curr_one->next=temp;
            curr_one = curr_one->next;
        }
        else{            
            curr_two->next =temp;
            curr_two = curr_two->next;
            }
       temp=temp->next; 
    }
     curr_two->next=nullptr;
     curr_one->next = (dummy_two->next)?dummy_two->next:nullptr;
    curr_zero->next = (dummy_one->next)?dummy_one->next:dummy_two->next;;
    
   

    cout<<"after: ";

    dummy_zero=dummy_zero->next;
    while (dummy_zero != nullptr)
    {
        
        cout << dummy_zero->data << "->";
        dummy_zero = dummy_zero->next;
    }
    cout << "null" << endl;
}