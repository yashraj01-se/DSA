#include <iostream>
#include <vector>
#include<algorithm>
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

int max_width(Node *root)
{
    if (root == nullptr)
        return 0;
    int ans = 0;
    queue<pair<Node *, unsigned long long>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int mmin = q.front().second;
        unsigned long long first, last;
        for (int i = 0; i < size; i++)
        {
            unsigned long long curr_id = q.front().second - mmin;
            Node *node = q.front().first;

            q.pop();
            if(i==0)first=curr_id;
            if(i==size-1)last=curr_id;
            if (node->left)
            {
                q.push({node->left, curr_id * 2 + 1});
            }
            if (node->right)
            {
                q.push({node->right, curr_id * 2 + 2});
            }
        }
        ans = max(ans, int(last - first + 1));
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->right->right = new Node(4);

    int ans = max_width(root);
    cout << ans;
}
