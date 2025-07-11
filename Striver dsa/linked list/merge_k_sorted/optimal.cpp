#include <algorithm>
#include <vector>
#include <iostream>
#include<queue>
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

int length(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int main()
{
    Node *head1 = new Node(2);
    head1->next = new Node(3);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(5);
    head1->next->next->next->next = new Node(6);

    Node *head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(4);
    head2->next->next->next = new Node(5);
    head2->next->next->next->next = new Node(6);

    Node *head3 = new Node(2);
    head3->next = new Node(3);
    head3->next->next = new Node(4);
    head3->next->next->next = new Node(5);
    head3->next->next->next->next = new Node(6);

    vector<Node *> lists = {head1, head2, head3};

    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
    for(int i=0;i<lists.size();i++){
        if(lists[i]){
        pq.push({lists[i]->data,lists[i]});
        }
    }
    Node* dummy=new Node(-1);
    Node* curr=dummy;

    while(!pq.empty()){
        auto p=pq.top();
        curr->next=p.second;
        pq.pop();
        curr=curr->next;
        if(p.second->next){
           pq.push({p.second->next->data,p.second->next});
        }
    }
    Node *temp=dummy->next;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"null";

}