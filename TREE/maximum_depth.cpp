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

int max_depth(Node *root){
    if(root==NULL)return;
    int left=max_depth(root->left);
    int right=max_depth(root->right);

    return 1+max(left,right);
}

int main(){
   struct Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);

    int height=max_depth(root);
    cout<<height;

}