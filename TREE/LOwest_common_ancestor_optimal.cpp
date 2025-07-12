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
 Node * LCA(Node * root, int a,int b){
     if(root==nullptr || root->data==a || root->data==b)return root;
     Node * left=LCA(root->left,a,b);
     Node * right=LCA(root->right,a,b);

     if(left==NULL){
        return right;
     }
     else if(right==NULL){
        return left;
     }
     else{
        return root;
     }
 }
int main(){
    Node * root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->left->right->right=new Node(7);
    root->right->left=new Node(8);
    root->right->right=new Node(9);

    Node * nas=LCA(root,7,8);
    cout<<nas->data;

}

