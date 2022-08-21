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
    
    void construct(TreeNode* root,vector<vector<int>> &adj){
        if(!root) return;
        construct(root->left,adj);
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);

        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);

        }
        construct(root->right,adj);

    }
    
    void bfs(vector<vector<int>> adj,vector<int> vis,int &ans,int start){
        queue<int> q;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int node=q.front();
                q.pop();
                vis[node]=1;
                for(auto i:adj[node]){
                    if(vis[i]==-1) q.push(i);
                }
            }
            ans++;
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        int ans=0;
        vector<vector<int>> adj(100001);
        construct(root,adj);
        vector<int> vis(100001,-1);
        bfs(adj,vis,ans,start);
        return ans-1;
    }
};