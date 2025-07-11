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
bool ismirror(Node *left,Node*right){
    if(!left && !right)return true;
    if(!left || !right)return false;
    if(left->data!=right->data)return false;
    return ismirror(left->left,right->right) && ismirror(left->right,right->left);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    bool answer=ismirror(root->left,root->right);
    if(answer){
        cout<<"Symetric";
    }
    else{
        cout<<"Non-Symetric";
    }

}