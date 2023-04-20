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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int size = q.size();
            int mn = q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second-mn;
                q.pop();
                if(i==0) first = index;
                if(i==size-1) last = index;
                if(node->left){
                    q.push({node->left,2*index});
                }
                if(node->right){
                    q.push({node->right,2*index+1});
                }
            }
            ans=max(ans,last-first+1);
        }
        
        return ans;
    }
};