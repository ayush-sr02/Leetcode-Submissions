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
    
    int mxheight(TreeNode* root){
        if(!root) return 0;
        int lheight=mxheight(root->left);
        int rheight=mxheight(root->right);
        return 1+max(lheight,rheight);
    }
    
    int maxDepth(TreeNode* root) {
        return mxheight(root);
    }
};