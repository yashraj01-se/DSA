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
int height(Node *root){
    if (root==nullptr)return 0;
    int left=height(root->left);
    int right=height(root->right);
    return 1+max(left,right);
}

bool is_balanced(Node *root){
    if(root==nullptr)return true;
    int lefth=height(root->left);
    int righth=height(root->right);

    if(abs(righth-lefth)>1)return false;

    bool leftside=is_balanced(root->left);
    bool rightside=is_balanced(root->right);

    if(!leftside || !rightside) return false;

    return true;
}
int main(){
    struct Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);

      bool answer=is_balanced(root);
      if(answer){
        cout<<"Balanced";
      }
      else{
        cout<<"Not Balanced";
      }
}