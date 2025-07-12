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
bool root_to_node(Node * root, vector<int>&ans,int b){
    if(root==NULL)return false;
    ans.push_back(root->data);
    if(root->data==b)return true;
    if(root_to_node(root->left,ans,b) || root_to_node(root->right,ans,b))return true;
    ans.pop_back();
    return false;
}
vector<int>answer(Node * root ,int lca_element){
    vector<int>ans;
    if(root==NULL)return ans;
    root_to_node(root,ans,lca_element);
    return ans;
}
int main(){
    Node * root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->left->right->right=new Node(7);
    root->right->left=new Node(8);
    root->right->right=new Node(9);

    int lca_first_ele=4;
    int lca_second_ele=7;

    vector<int>path1=answer(root,lca_first_ele);
    vector<int>path2=answer(root,lca_second_ele);

    int i = 0;
while(i < path1.size() && i < path2.size()){
    if(path1[i] != path2[i]) break;
    i++;
}
cout << "Lowest Common Ancestor: " << path1[i-1] << endl;



}