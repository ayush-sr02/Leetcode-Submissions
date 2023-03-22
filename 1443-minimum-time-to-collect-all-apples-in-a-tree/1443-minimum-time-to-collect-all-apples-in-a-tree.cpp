class Solution {
public:

    int dfs(int i,vector<int> adj[],vector<bool>&apple,vector<int>&vis){
        vis[i]=1;
        int cost=0;
        for(auto it:adj[i]){
            if(!vis[it]){
                int temp = dfs(it,adj,apple,vis);
                if(temp>0 or apple[it]) cost+=(temp+2);
            }
        }
        return cost;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& apple) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        return dfs(0,adj,apple,vis);
    }
};