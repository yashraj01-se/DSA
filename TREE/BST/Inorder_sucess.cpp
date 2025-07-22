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

int insucc(Node *root, int x)
{
    if (root == nullptr)
        return -1;
    Node *succ = nullptr;
    while (root != nullptr)
    {
        if (x < root->data)
        {
            succ = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return succ ? succ->data : -1;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    root->right->right->right = new Node(10);
    root->right->right->left = new Node(8);

    int res = insucc(root, 8);
    cout <<"Inorder Successor : "<< res;
}