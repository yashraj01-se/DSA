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
    if(root==NULL)return 0;
    int left=max_depth(root->left);
    if (left== -1) return -1;
    int right=max_depth(root->right);
    if (right== -1) return -1;

    if(abs(left-right)>1)return -1;

    return 1+max(left,right);
}
bool checker(Node *root){
    return max_depth(root);
}

int main(){
   struct Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);

   bool ans=checker(root);
   if(ans){
    cout<<"Balanced";
   }
   else{
    cout<<"NOn-balanced";
   }
}