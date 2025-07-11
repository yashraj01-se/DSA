#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
vector<int>top_view(Node *root){
    map<int,int>mpp;//vertical,value; ..becaue it stores in sorted order....
    queue<pair<Node*,int>>q;//node,vertical;
    q.push({root,0});
    while(!q.empty()){
        auto first_node=q.front();
        Node* curr=first_node.first;
        int line=first_node.second;
        q.pop();
        mpp[line] = curr->data;
        if (curr->left) q.push({curr->left, line - 1});
        if (curr->right) q.push({curr->right, line + 1});
    }
    vector<int>ans;
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right= new Node(7);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);

    vector<int>answer=top_view(root);
    for(auto it:answer){
        cout<<it<<" ";
    }
}