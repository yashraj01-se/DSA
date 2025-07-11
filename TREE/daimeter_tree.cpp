#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int MAXI=INT_MIN;
struct Node{
    int data;
    Node*left;
    Node*right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
int height(Node *root){
    if (root==nullptr)return 0;
    int left=height(root->left);
    int right=height(root->right);
    return 1+max(left,right);
}
void daimeter(Node * root){
    if(root==NULL)return ;
    int left=height(root->left);
    int right=height(root->right);
    MAXI=max(MAXI,left+right);

    daimeter(root->left);
    daimeter(root->right);

}
int main(){
   struct Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);

  daimeter(root);
  cout<<MAXI;

}