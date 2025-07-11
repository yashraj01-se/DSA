#include <iostream>
#include <stack>
#include <vector>
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
    head->next->back = head;
    head->next->next = new Node(8);
    head->next->next->back = head->next;
    int k = 10;
    Node *temp = head;

    vector<pair<int, int>> ans;

    Node *left = head;
    Node *right = head;
    while (right->next!= nullptr)
    {
        right = right->next;
    }
    while (left->data<right->data)
    {
        if (left->data + right->data > k)
        {
            right = right->back;
        }
        else if (left->data + right->data < k)
        {
            left = left->next;
        }
        else
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        }
    }
    for (auto it : ans)
    {
        cout << it.first << " " << it.second << " " << endl;
    }
}