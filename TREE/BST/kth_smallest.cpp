#include <iostream>
#include <vector>
#include <map>
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
int counter=0;
int result=-1;
void inorder(Node* root,int k){
     if(root==nullptr)return;
     inorder(root->left,k);
     counter++;
     if(counter==k){
         result=root->data;
         return;
     }
     inorder(root->right,k);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    inorder(root,5);
    cout<<result;

}
