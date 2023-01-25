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
    
    bool check(TreeNode* root,long long low,long long high){
        if(!root) return true;
        if(root->val>=high or root->val<=low) return false;
        return check(root->left,low,root->val) and check(root->right,root->val,high);
    }
    
    bool isValidBST(TreeNode* root) {
        long long min = LONG_MIN;
        long long max = LONG_MAX;
        return check(root,min,max);
    }
};