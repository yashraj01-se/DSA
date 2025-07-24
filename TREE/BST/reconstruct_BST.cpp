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

void inorder(Node *root,Node* &prev,Node* &first,Node* &second)
{
    if(root==nullptr)return;
    inorder(root->left,prev,first,second);

    if (prev && prev->data > root->data)
    {
        if (!first)
            first = prev;
        second = root;
    }
    prev = root;

    inorder(root->right,prev,first,second);
}
void inorderprint(Node *root)
{
    if(root==nullptr)return;
    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}
int main()
{
    Node *root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(3);

    Node *first = nullptr;
    Node *second = nullptr;
    Node *prev = nullptr;

    cout << "Wrong Tree (Inorder): ";
    inorderprint(root);
    cout << endl;

    // Step 1: Detect wrong nodes
    inorder(root, prev, first, second);

    // Step 2: Fix the swapped nodes
    if (first && second)
        swap(first->data, second->data);

    cout << "Correct BST (Inorder): ";
    inorderprint(root);
    cout << endl;

    return 0;
}