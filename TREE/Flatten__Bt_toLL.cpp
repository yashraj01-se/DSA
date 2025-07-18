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

void preorder_flatten(Node *root, Node *&prev)
{
    if (root == NULL)
        return;
    preorder_flatten(root->right, prev);
    preorder_flatten(root->left, prev);
    root->right = prev;
    root->left = nullptr;
    prev = root;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    Node *prev = nullptr;
    preorder_flatten(root, prev);
    Node *curr = root;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
}