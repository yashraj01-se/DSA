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
vector<int>right_view(Node * root){
    vector<int> ans;
    if (!root) return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node *curr=q.front();
            q.pop();
            if(i==size-1){
                ans.push_back(curr->data);
            }
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
        }
        
    }
    return ans;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
   
    vector<int>answer=right_view(root);
    for(auto it: answer){
        cout<<it<<" ";
    }
}