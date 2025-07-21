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

bool validator(Node * node,long min,long max){
    if(node==nullptr)return true;
    if(node->data<=min || node->data>=max)return false;
    return validator(node->left,min,node->data) && validator(node->right,node->data,max);
}
 bool isValidBST(Node* root){
     return validator(root,LONG_MIN,LONG_MAX);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(0);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    bool isValid=isValidBST(root);
    if(isValid){
        cout<<"Valid BST";
    }
    else{
        cout<<"Invalid BST";
    }
}