#include <iostream>
#include <vector>
#include <algorithm>
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

void changeTree(Node *root)
{
    if (root == nullptr)
        return;
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child >= root->data)
        root->data = child;
    else
    {
        if (root->left)
            root->left->data = root->data;
        else if (root->right)
            root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;
    if (root->left || root->right)
        root->data = total;
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->left->left->left=new Node(1);
    root->right->left = new Node(12);
    root->right->right = new Node(20);
    root->right->left->right=new Node(3);

    changeTree(root);
    inorder(root);
}