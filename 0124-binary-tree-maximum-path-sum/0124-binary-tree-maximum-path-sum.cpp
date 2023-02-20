/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mx=INT_MIN;
    
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL){
            mx=max(mx,root->val);
            return max(0,root->val);
        }
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        mx=max(mx,root->val);
        mx=max(mx,(root->val+leftSum+rightSum));
        mx=max(mx,root->val+leftSum);
        mx=max(mx,root->val+rightSum);
        return root->val+max(leftSum,rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return mx;
    }
};