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
    
    bool check(TreeNode* p,TreeNode* q){
        if(p==NULL or q==NULL) return p==q; 
        return p->val==q->val and check(p->left,q->left) and check(p->right,q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};