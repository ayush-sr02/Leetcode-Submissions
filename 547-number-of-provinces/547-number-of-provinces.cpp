class Solution {
public:
    
    void dfs(vector<int> adj[],vector<int> &vis,int node){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(adj,vis,i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& c) {
        int n=c.size();
        vector<int> adj[n+1];
        vector<int> vis(n+1,0);
        for(int i=0;i<c.size();i++){
            for(int j=0;j<c[0].size();j++){
                if(c[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                cnt++;
            }
        }
        return cnt; 
    }
};