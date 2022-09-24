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
    vector<vector<int>> ans;
    
    void solve(TreeNode* root,int target,int sum,vector<int> temp){
        if(!root){
            return;
        }
        temp.push_back(root->val);
        sum+=root->val;
        if(!root->left and !root->right){
            if(sum==target){
                ans.push_back(temp);
            }
        }
        solve(root->left,target,sum,temp);
        solve(root->right,target,sum,temp);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        int sum=0;
        vector<int> temp;
        solve(root,target,sum,temp);
        return ans;
    }
};