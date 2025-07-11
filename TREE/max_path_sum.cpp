#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int maxi=0;
struct Node{
    int data;
    Node*left;
    Node*right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
int maxdown(Node* root,int& maxi){
   if(root==NULL) return 0;
//    int leftpath=maxdown(root->left,maxi);
//    int rightpath=maxdown(root->right,maxi); // if no negative node...
    int leftpath=max(0,maxdown(root->left,maxi));
    int rightpath=max(0,maxdown(root->right,maxi));
   maxi=max(maxi,leftpath+rightpath+root->data);
   return root->data+max(leftpath,rightpath);
}
int main(){
   struct Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);
   
    int maxi=0;
    maxdown(root,maxi);
    cout<<maxi;

}