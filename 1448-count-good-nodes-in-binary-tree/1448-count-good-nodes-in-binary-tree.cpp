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
    
    void solve(TreeNode* root,int mx){
        if(!root) return;
        if(root->val>=mx){
            ans++;
            mx=root->val;
        } 
        solve(root->left,mx);
        solve(root->right,mx);
    }
    
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        solve(root,INT_MIN);
        return ans;
    }
};