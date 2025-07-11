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
vector<vector<int>> vertical_order(Node *root)
{
    map<int, map<int, multiset<int>>> nodes; // MAp to store verticles along with different level containing mutiple nodes..
    queue<pair<Node *, pair<int, int>>> q;   // queue(cotains)<node*,<vertical,level>>
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto first_root = q.front();
        q.pop();
        Node *node = first_root.first;
        int vertical = first_root.second.first, level = first_root.second.second;
        nodes[vertical][level].insert(node->data);
        if (node->left)
        {
            q.push({node->left, {vertical - 1, level + 1}});
        }
        if (node->right)
        {
            q.push({node->right, {vertical + 1, level + 1}});
        }
    }
    vector<vector<int>>ans;
    for(auto p:nodes){
        vector<int>col;
        for(auto i:p.second){
            col.insert(col.end(),i.second.begin(),i.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
   
     vector<vector<int>>answer=vertical_order(root);
    for(auto it: answer){
        for(auto i:it){
            cout<<i<<" ";
        }
    }
}