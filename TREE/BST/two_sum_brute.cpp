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
//         bool hastwo=false;
//         for(int i=0;i<ans.size();i++){
//             for(int j=i+1;j<ans.size();j++){
//                 if(ans[i]+ans[j]==k){
//                     hastwo=true;
//                 }
//             }
//         }
//         return hastwo;
//     }
// };