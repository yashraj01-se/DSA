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
Node *prebuilt(vector<int> &preorder, int i, int min, int max)
{
    if (i >= preorder.size() || preorder[i] < min || preorder[i] > max)
    {
        return nullptr;
    }
    Node *root = new Node(preorder[i++]);
    root->left = prebuilt(preorder, i, min, root->data);
    root->right = prebuilt(preorder, i, root->data, max);
    return root;
}

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10};
    Node *root = prebuilt(preorder, 0, INT_MIN, INT_MAX);
}