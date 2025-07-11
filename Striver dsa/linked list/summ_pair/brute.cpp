#include <iostream>
#include <stack>
#include<vector>
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
    Node *head = new Node(2);
    head->next = new Node(8);
    head->next->back = head; 
    head->next->next = new Node(1);
    head->next->next->back = head->next; 
    int k=10;

     vector<pair<int,int>>ans;
    for(Node *temp1=head;temp1!=nullptr;temp1=temp1->next){
        for(Node *temp2=temp1->next;temp2!=nullptr;temp2=temp2->next){
            if(temp1->data+temp2->data==k){
                ans.push_back({temp1->data,temp2->data});
            }
        }
    }
 for (auto it : ans) {
    cout << it.first << " " << it.second << endl;
}


   



}