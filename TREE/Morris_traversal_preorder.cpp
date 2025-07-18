#include <iostream>
#include <vector>
#include <map>
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

vector<int>morris_traversal_preorder(Node *root){
    vector<int>ans;
    Node *curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            ans.push_back(curr->data);
            curr=curr->right;
        }
        else{
            Node*prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==nullptr){
                ans.push_back(curr->data);
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=nullptr;
                curr=curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right=new Node(6);


    vector<int>ans=morris_traversal_preorder(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
}