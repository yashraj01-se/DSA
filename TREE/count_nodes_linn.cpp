#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
int leftheight(Node* root){
    int lh=0;
    while(root){
        lh++;
        root=root->left;
    }
    return lh;
}
int rightheight(Node* root){
    int rh=0;
    while(root){
        rh++;
        root=root->right;
    }
    return rh;
}
int countNode(Node* root){
    if(root==nullptr)return 0;
    
    int lh=leftheight(root);
    int rh=rightheight(root);

    if(lh==rh){
        return (1<<lh)-1;
    }
    return 1+countNode(root->left)+countNode(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left=new Node(10);
    root->left->right->right=new Node(11);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

   int count=countNode(root);
   cout<<"Number of nodes: "<<count<<endl;

}