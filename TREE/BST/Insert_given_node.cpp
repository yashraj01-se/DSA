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

Node *insert(Node *root, int X)
{
    if (root == nullptr)
    {
        return new Node(X);
    }
    Node *curr = root;
    while (true)
    {
        if (X < curr->data)
        {
            if (curr->left == nullptr)
            {
                curr->left = new Node(X);
                break;
            }
            curr = curr->left;
        }
        else
        {
            if (curr->right == nullptr)
            {
                curr->right = new Node(X);
                break;
            }
            curr = curr->right;
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(3);

    int x = 7;
    Node *real_root = insert(root, x);
}