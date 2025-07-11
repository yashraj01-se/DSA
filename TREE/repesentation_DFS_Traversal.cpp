#include<iostream>
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
void inorder(Node*root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node*root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    struct Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);
    cout<<"Inorder traversal"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal"<<endl;
    postorder(root);
    cout<<endl;

}