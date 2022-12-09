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
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int value = root->val;
        return solution(root,value,value);
    }
    
    int solution(TreeNode* root,int mx,int mn){
        if(root==NULL) return mx-mn;
        mx = max(mx,root->val);
        mn = min(mn,root->val);
        int left = solution(root->left,mx,mn);
        int right = solution(root->right,mx,mn);
        return max(left,right);
    }
};