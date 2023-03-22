class Solution {
public:
    int ans=-1;
    void dfs(vector<int> adj[],vector<int> &vis,vector<int> &pathVis,int i,int cnt){
        vis[i]=1;
        pathVis[i]=cnt;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(adj,vis,pathVis,it,cnt+1);
            }else if(pathVis[it]){
                ans=max(ans,cnt-pathVis[it]+1);
            }
        }
        pathVis[i]=0;
    }
    
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> vis(n,0),pathVis(n,0);
        for(int i=0;i<n;i++){
            int cnt=1;
            if(!vis[i]){
                dfs(adj,vis,pathVis,i,cnt);
            }
        }
        return ans;
    }
};