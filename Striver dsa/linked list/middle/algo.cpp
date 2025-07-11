#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *merge(Node *lefthead, Node *righthead)
{
    Node *dummy = new Node(-1);
    Node *curr = dummy;
    Node *temp1 = lefthead;
    Node *temp2 = righthead;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->data > temp2->data)
        {
            curr->next = temp2;
            temp2 = temp2->next;
            curr = curr->next;
        }
        else
        {
            curr->next = temp1;
            temp1 = temp1->next;
            curr = curr->next;
        }
    }
    while (temp1 != nullptr)
    {
        curr->next = temp1;
        temp1 = temp1->next;
        curr = curr->next;
    }
    while (temp2 != nullptr)
    {
        curr->next = temp2;
        temp2 = temp2->next;
        curr = curr->next;
    }
    return dummy->next;
}
Node *mid(Node *head1)
{
    Node *slow = head1;
    Node *fast = head1->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *mergesort(Node *head1)
{
    if (head1 == nullptr || head1->next == nullptr)
    {
        return head1;
    }
    Node *middle = mid(head1);
    Node *righthead = middle->next;
    middle->next=nullptr;
    Node *lefthead = head1;
   
    lefthead = mergesort(lefthead);
    righthead = mergesort(righthead);
    return merge(lefthead, righthead);
}
int main()
{
    Node *head1 = new Node(3);
    head1->next = new Node(2);
    head1->next->next = new Node(1);
    head1->next->next->next = new Node(5);
    head1->next->next->next->next = new Node(9);

    Node *head=mergesort(head1);
    while(head!=nullptr){
        cout<<head->data<<"->";
        head=head->next;
    }cout<<"null";
}