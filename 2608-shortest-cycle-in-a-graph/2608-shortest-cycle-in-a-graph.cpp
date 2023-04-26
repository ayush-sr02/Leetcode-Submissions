class Solution {
public:
    int ans=1e9;
    
    void bfs(vector<int> adj[],int n,int nd){
        vector<int> dis(n,-1);
        vector<int> par(n,-1);
        queue<int> q;
        q.push(nd);
        dis[nd]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dis[it]==-1){
                    q.push(it);
                    dis[it]=dis[node]+1;
                    par[it]=node;
                }
                else if(par[node]!=it and par[it]!=node){
                    ans=min(ans,dis[node]+dis[it]+1);
                }
            }
        }
    }
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            bfs(adj,n,i);
        }
        return ans==1e9?-1:ans;
    }
};