/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool find(vector<int> &v,TreeNode* p,TreeNode* root){
        if(root==NULL) return false;
        v.push_back(root->val);
        if(root==p) return true;
        if(find(v,p,root->left) or find(v,p,root->right)) return true;
        v.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> v1,v2;
        find(v1,p,root);
        find(v2,q,root);
        TreeNode* ans=new TreeNode(-1);
        int i=0,j=0;
        while(i<v1.size() and j<v2.size()){
            if(v1[i]==v2[j]){
                ans->val=v1[i];
                i++;j++;
            }else break;
        }
        return ans;
    }
};