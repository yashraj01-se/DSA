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
int N=0;
void preorder(Node *root){
    if(root==nullptr){
        return;
    }
    else{
        N++;
    }
    preorder(root->left);
    preorder(root->right);
}

int counter=0;
int result=-1;
void inorder(Node* root,int k){
     if(root==nullptr)return;
     inorder(root->left,k);
     counter++;
     if(counter==N-k+1){
         result=root->data;
         return;
     }
     inorder(root->right,k);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right=new Node(15);

    preorder(root);
    int k=6;
    inorder(root,k);
    cout<<k<<"st largset Element in the BST : "<<result;

}
