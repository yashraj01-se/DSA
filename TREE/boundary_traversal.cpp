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
bool isLeaf(Node* root){
    return root!=nullptr && root->left==nullptr && root->right==nullptr;
}
void addLeftBoundary(Node* root,vector<int>&ans){
       Node* curr=root->left;
       while(curr){
        if(!isLeaf(curr))ans.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else curr=curr->right;
       }
}
void addRightBoundary(Node* root,vector<int>&ans){
     Node*curr=root->right;
     vector<int>temp;
     while(curr){
        if(!isLeaf(curr))temp.push_back(curr->data);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
     }
     for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
     }
}
void addLeaf(Node* root,vector<int>&ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left)addLeaf(root->left,ans);
    if(root->right)addLeaf(root->right,ans);

}
vector<int>printBoundary(Node* root){
    vector<int>ans;
    if(root==nullptr)return ans;
    if(!isLeaf(root))ans.push_back(root->data);
    addLeftBoundary(root,ans);
    addLeaf(root,ans);
    addRightBoundary(root,ans);
    return ans;
}
int main(){
     struct Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);

     vector<int>answer=printBoundary(root);
    for(auto it: answer){
        cout<<it<<" ";
    }

}