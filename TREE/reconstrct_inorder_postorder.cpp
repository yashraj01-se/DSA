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
Node *TreeBuild(vector<int> &inorder, int instart, int inend, vector<int> &postorder, int poststart, int postend, map<int, int> inmap)
{

    if ((poststart > postend) || (instart > inend))
        return NULL;

    Node *root = new Node(postorder[postend]);

    int inroot = inmap[root->data];
    int numsleft = inroot - instart;

    root->left = TreeBuild(inorder, instart, inroot - 1,postorder, poststart, poststart + numsleft-1 ,inmap);
    root->right = TreeBuild( inorder, inroot + 1, inend,postorder, poststart + numsleft, postend-1, inmap);

    return root;
}


Node *treebuild(vector<int> &inorder, vector<int> &postorder)
{
    map<int, int> inmap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inmap[inorder[i]] = i;
    }
    return TreeBuild(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
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
    vector<int> postorder = {40, 50, 10, 60, 30, 10};

    Node *root = treebuild(inorder, postorder);
    printInorder(root);
    cout<<endl;
}