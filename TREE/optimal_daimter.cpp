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
int findmax(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftheight=findmax(root->left);
    int rightheight=findmax(root->right);

    MAXI=max(MAXI,leftheight+rightheight); 
    return 1+max(leftheight,rightheight);
}
int main(){
   struct Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);
    
    findmax(root);     // we only care about updating MAXI
    cout << "Diameter (in edges): " << MAXI << endl;
}