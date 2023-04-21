class Solution {
public:
    
    void dfs(vector<int> adj[],int node,vector<int> &vis,map<int,set<int>> &mp,int parent){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                mp[parent].insert(it);
                dfs(adj,it,vis,mp,parent);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i:edges){
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<int>> ans(n);
        map<int,set<int>> mp;

        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            dfs(adj,i,vis,mp,i);
        }
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(auto it:mp[i]){
                temp.push_back(it);
            }
            ans[i] = temp;
        }
        return ans;
    }
};