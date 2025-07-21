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

Node *righter(Node *root)
{
    if (root->right == nullptr)
    {
        return root;
    }
    return righter(root->right);
}

Node *helper(Node *root)
{
    if (root->left == nullptr)
    {
        return root->right;
    }
    if (root->right == nullptr)
    {
        return root->left;
    }
    Node *rightchild = root->right;
    Node *rightmost = righter(root->left);
    rightmost->right = rightchild;
    return root->left;
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *DeleteNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == key)
    {
        return helper(root);
    }
    Node *dummy = root;
    while (root != nullptr)
    {
        if (root->data > key)
        {
            if (root->left != nullptr && root->left->data == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != nullptr && root->right->data == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(3);

    cout << "Nodes Before Delete:" << endl;
    inorder(root);
    cout << endl;
    int x = 7;
    DeleteNode(root, x);
    cout << "Node After Delete:" << endl;
    inorder(root);
    return 0;
}