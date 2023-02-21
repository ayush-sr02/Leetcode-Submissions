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
    vector<string> ans;
    
    void solve(TreeNode* root,string s){
        if(root==NULL) return;
        char t=root->val+'a';
        s+=t;
        if(root->left==NULL and root->right==NULL){
            string temp=s;
            reverse(begin(temp),end(temp));
            ans.push_back(temp);
        }
        solve(root->left,s);
        solve(root->right,s);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        solve(root,s);
        // for(auto i:ans) cout<<i<<" ";
        sort(begin(ans),end(ans));
        return ans[0];
    }
};