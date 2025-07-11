#include <algorithm>
#include <vector>
#include <iostream>
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

    // answer
    vector<int> ans;
    for (int i = 0; i < lists.size(); i++)
    {
        Node *temp = lists[i];
        while (temp != nullptr)
        {
            ans.push_back(temp->data);
            temp = temp->next;
        }
    }

    sort(ans.begin(), ans.end());

    Node *head =new Node(ans[0]);
    Node*temp=head;
    for(int i=1;i<ans.size();i++){
        Node*nw=new Node(ans[i]);
        temp->next=nw;
        temp=temp->next;
    }

    while(head!=nullptr){
        cout<<head->data<<"->";
        head=head->next;
    }cout<<"null";
}