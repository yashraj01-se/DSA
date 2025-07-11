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
vector<int> preorder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *first = s.top();
        s.pop();
        ans.push_back(first->data);
        if (first->right)
            s.push(first->right);
        if (first->left)
            s.push(first->left);
    }
    return ans;
}
vector<int> inorder(Node *root)
{
    stack<Node *> s;
    vector<int> ans;
    Node *first = root;
    while (true)
    {
        if (first != NULL)
        {
            s.push(first);
            first = first->left;
        }
        else
        {
            if (s.empty())
                break;
            first = s.top();
            s.pop();
            ans.push_back(first->data);
            first = first->right;
        }
    }
    return ans;
}
vector<int> postorder(Node *root)
{
    Node *curr = root;
    vector<int> ans;
    stack<Node *> st;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return ans;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    cout << "Preorder Traversal:" << endl;
    vector<int> answer = preorder(root);
    for (auto it : answer)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "Inorder Traversal:" << endl;
    vector<int> answeri = inorder(root);
    for (auto it : answeri)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "Postorder Traversal:" << endl;
    vector<int> answerp = postorder(root);
    for (auto it : answerp)
    {
        cout << it << " ";
    }
    cout << endl;
}