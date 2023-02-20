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
    
    int ans=0;
    
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int lheight=solve(root->left);
        int rheight=solve(root->right);
        ans=max(ans,lheight+rheight);
        return max(lheight,rheight)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};