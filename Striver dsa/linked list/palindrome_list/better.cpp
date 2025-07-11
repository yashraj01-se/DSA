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
Node *reverseList(Node* second)
{
    Node *prev = nullptr;
    Node *temp = second;
    Node *front;
    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
    int main()
    {
        Node *head = new Node(1);
        head->next = new Node(2);
        head->next->next = new Node(3);
        head->next->next->next = new Node(2);
        head->next->next->next->next=new Node(1);
        Node *temp=head;

        // step 1:find the middle:
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // middle will be slow->next...
        // step 2: reverse the another half:
        Node *second = slow;
        Node * new_head=reverseList(second);
        
        while(new_head!=nullptr){
            if(temp->data!=new_head->data){
                cout<<"Not a palindrome";
                return 0;
            }
            temp=temp->next;
            new_head=new_head->next;
        }
        cout<<"ITs s palindrome";
        return 0;

    }