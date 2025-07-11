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

void inorder(Node * root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void kthsmallest(Node * root,int k){
       int smallest=0;
    
       int Kthnode=root->data;
       while (inorder )
       {
         if(smallest<root->data){
            smallest=root->data;
            Kthnode=min(Kthnode,smallest);
         }
       }
       
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

}