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
    
    void solve(TreeNode* root,int zigzag,bool flag){
        if(root==nullptr) return;
        if(root->left){
            if(flag==false){
                ans=max(ans,zigzag+1);
                solve(root->left,zigzag+1,!flag);
            }else{
                solve(root->left,1,flag);
            }
        }
        if(root->right){
            if(flag==true){
                ans=max(ans,zigzag+1);
                solve(root->right,zigzag+1,!flag);
            }else{
                solve(root->right,1,flag);
            }
        }
    }
    
    int longestZigZag(TreeNode* root) {
        bool flag=true;
        solve(root,0,flag);
        return ans;
    }
};