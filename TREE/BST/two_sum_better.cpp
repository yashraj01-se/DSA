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
// class Solution {
// public:
// vector<int>ans;
// void inorder(TreeNode* root){
//     if(root==nullptr)return;
//     inorder(root->left);
//     ans.push_back(root->val);
//     inorder(root->right);
// }
//     bool findTarget(TreeNode* root, int k) {
//         inorder(root);
//         int i=0;
//         int j=ans.size()-1;
//         while(i<j){
//             int sum=ans[i]+ans[j];
//             if(sum==k)return true;
//             int rem=k-ans[i];
//             if(rem>ans[j]){
//                 i++;
//             }
//             else{
//                 j--;
//             }
//         }
//         return false;
//     }
//  };