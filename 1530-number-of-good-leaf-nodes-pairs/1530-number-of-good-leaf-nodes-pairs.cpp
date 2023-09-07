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
    multiset<TreeNode*> leaf;
    void makeParent(TreeNode* root,unordered_map<TreeNode*,vector<TreeNode*>> &parent){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(!node->left and !node->right) leaf.insert(node);
            if(node->left){
                q.push(node->left);
                parent[node->left].push_back(node);
                parent[node].push_back(node->left);
            }
            if(node->right){
                q.push(node->right);
                parent[node->right].push_back(node);
                parent[node].push_back(node->right);
            }
        }
    } 
    
    int countPairs(TreeNode* root, int d) {
        unordered_map<TreeNode*,vector<TreeNode*>> parent;
        makeParent(root,parent);
        int ans=0;
        for(auto i:leaf){
            set<TreeNode*> vis;
            queue<pair<TreeNode*,int>> q;
            q.push({i,0});
            vis.insert(i);
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                if(node.second>d) break;
                if(leaf.count(node.first) and node.first!=i) ans++;
                for(auto j:parent[node.first]){
                    if(!vis.count(j)){
                        q.push({j,node.second+1});
                        vis.insert(j);
                    }
                }
            }
        }
        return ans/2;
    }
};