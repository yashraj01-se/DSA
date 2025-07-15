#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
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

void parent(Node *root, unordered_map<Node *, Node *>&parentmaker)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push({root});
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->left)
        {
            parentmaker[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            parentmaker[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

int main()
{
    Node *target;
    Node *root = new Node(3);
    target = root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    unordered_map<Node *, Node *> parentMaker;
    parent(root, parentMaker);

    unordered_map<Node*,bool>visited;
    queue<Node*>q;
    int k=2;
    q.push(target);
    int dis=0;
    visited[target]=true;
    while(!q.empty()){
        int size=q.size();
        if(dis==k)break;
        dis++;
        for(int i=0;i<size;i++){
            Node * curr=q.front();
            q.pop();
            if(curr->left && !visited[curr->left]){
                q.push(curr->left);
                visited[curr->left]=true;
            }
             if(curr->right && !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right]=true;
            }
            if(parentMaker[curr] && !visited[parentMaker[curr]]){
                q.push(parentMaker[curr]);
                visited[parentMaker[curr]]=true;
            }
        }

    }
    vector<int>result;
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        result.push_back(curr->data);
    }

    for(auto it : result){
        cout<<it<<" ";
    }
}