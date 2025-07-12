#include <iostream>
#include <vector>
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
bool root_to_node(Node *root, vector<int> &ans, int b)
{
    if (root == NULL)
        return false;
    ans.push_back(root->data);
    if (root->data == b)
        return true;
    if (root_to_node(root->left, ans, b) || root_to_node(root->right, ans, b))
        return true;
    ans.pop_back();
    return false;
}
vector<int> answer(Node *root)
{
    vector<int> answer;
    if (root == NULL)
        return answer;

    root_to_node(root, answer, 7);
    return answer;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int> ans = answer(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}