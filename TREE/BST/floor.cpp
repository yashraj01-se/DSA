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
int FindFLOOR(Node *root, int x)
{
    int floor = INT_MIN;
    while (root != nullptr)
    {
        if (root->data == x)
        {
            floor = root->data;
            return floor;
        }
        if (root->data > x)
        {
            root = root->left;
        }
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(6);

    int x = 7;
    int ceil = FindFLOOR(root, x);
    cout << ceil;
}