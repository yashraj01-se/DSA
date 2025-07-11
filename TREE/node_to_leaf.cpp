#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void root_to_node(Node* root,vector<int>&ans,vector<vector<int>>&result){
        if(root==nullptr)return;
        ans.push_back(root->data);
       
        if(root->left==nullptr && root->right==nullptr){
            result.push_back(ans);
        }
        else{
            root_to_node(root->left,ans,result);
            root_to_node(root->right,ans,result);
        }
      

    ans.pop_back();

}
vector<vector<int>>answer(Node * root){
    vector<int>ans;
    vector<vector<int>>result;
    if(root==nullptr){
        result.push_back(ans);
    }
    root_to_node(root,ans,result);
    return result;
}
int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<vector<int>>ans=answer(root);
    for(auto & it:ans){
       for(auto i:it){
        cout<<i<<" ";
       }cout<<endl;
    }

}