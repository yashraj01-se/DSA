#include <iostream>
#include <vector>
#include <stack>
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
stack<Node*>stl,str;
void hasleft(Node * root){
    while(root!=nullptr){
      stl.push(root);
      root=root->left;
    }
}
void hasright(Node * root){
    while(root!=nullptr){
      str.push(root);
      root=root->right;
    }
}
int next(){
    Node* node=stl.top();
    stl.pop();
    hasleft(node->right);
    return node->data;
}
int before(){
    Node* node=str.top();
    str.pop();
    hasright(node->left);
    return node->data;
}

int main()
{
    Node *root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->left->left->left=new Node(1);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(4);
    root->right->right=new Node(11);
    root->right->left=new Node(9);
    root->right->left->left=new Node(8);
    int k=16;
    hasleft(root);
    hasright(root);
    int i=next();
    int j=before();
    bool has=false;
    while(i<j){
        int sum=i+j;
        if(sum==k)has=true;
        if(sum<k){
            i=next();
        }
        else{
            j=before();
        }
    }
 
    if(has){
        cout<<"Founded"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
  

}