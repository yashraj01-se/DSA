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
Node *TreeBuild(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, map<int, int> inmap)
{

    if ((prestart > preend) || (instart > inend))
        return NULL;

    Node *root = new Node(preorder[prestart]);

    int inroot = inmap[root->data];
    int numsleft = inroot - instart;

    root->left = TreeBuild(preorder, prestart + 1, prestart + numsleft, inorder, instart, inroot - 1, inmap);
    root->right = TreeBuild(preorder, prestart + numsleft + 1, preend, inorder, inroot + 1, inend, inmap);

    return root;
}

Node *treebuild(vector<int> &inorder, vector<int> &preorder)
{
    map<int, int> inmap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inmap[inorder[i]] = i;
    }
    return TreeBuild(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
}

void printInorder(Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> preorder = {10, 20, 40, 50, 30, 60};

    Node *root = treebuild(inorder, preorder);
    printInorder(root);
    cout<<endl;
}