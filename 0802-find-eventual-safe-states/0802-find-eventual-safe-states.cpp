class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph,int node,vector<int> &vis,vector<int> &pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(auto i:graph[node]){
            if(!vis[i]){
                if(dfs(graph,i,vis,pathVis)) return true;
            }
            else if(pathVis[i]) return true;
        }
        pathVis[node]=0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0),pathVis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,i,vis,pathVis);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!pathVis[i]) ans.push_back(i);
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};