#include <iostream>
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
Node *searchBST(Node *root, int val)
{
    while (root != nullptr && root->data != val)
    {
        root = val > root->data ? root->right : root->left;
    }
    return root;
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->right = new Node(14);
    root->right->left = new Node(10);
    root->right->right->left = new Node(13);

    int val = 7;
    Node *found = searchBST(root, val);

    if (found)
    {
        cout << "Founded" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}
