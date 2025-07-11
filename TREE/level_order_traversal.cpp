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
vector<vector<int>>level_order_traversal(Node* root){
    vector<vector<int>>ans;
    if(root==NULL)return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
       int size=q.size();
       vector<int>level;
       for(int i=0;i<size;i++){
        Node*first=q.front();
        q.pop();
        if(first->left)q.push(first->left);
        if(first->right)q.push(first->right);
        level.push_back(first->data);
       }
      ans.push_back(level);      
    }
    return ans;
}
int main(){
   struct Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);

    vector<vector<int>>answer=level_order_traversal(root);
    for(auto it: answer){
        for(auto i:it){
            cout<<i<<" ";
        }
    }
}