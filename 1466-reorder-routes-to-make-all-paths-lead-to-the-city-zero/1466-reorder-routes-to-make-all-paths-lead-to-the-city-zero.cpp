class Solution {
public:
    int ans=0;
    
    void dfs(vector<int>adj[],vector<int>&vis,int i){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[abs(it)]){
                if(it>0) ans++;
                dfs(adj,vis,abs(it));
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(-i[0]);
        }
        vector<int> vis(n,0);
        dfs(adj,vis,0);
        return ans;
    }
};