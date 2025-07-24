// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */


// #include<vector>
// class BSTIterator {
// public:
// vector<int>inorder;
// int i=0;
// void inorderTraversal(TreeNode* root) {
//         if (root == nullptr) return;
//         inorderTraversal(root->left);
//         inorder.push_back(root->val);
//         inorderTraversal(root->right);
//     }
//     BSTIterator(TreeNode* root) {
//        inorderTraversal(root);
//     }
    
//     int next() {
//        return inorder[i++];
//     }
    
//     bool hasNext() {
//         return i < inorder.size();
//     }
// };


// /**
//  * Your BSTIterator object will be instantiated and called as such:
//  * BSTIterator* obj = new BSTIterator(root);
//  * int param_1 = obj->next();
//  * bool param_2 = obj->hasNext();
//  */