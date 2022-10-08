class Solution {
public:
    vector<int> ans;
    bool cycle(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int> &pathvis,vector<int> &check){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(cycle(it,graph,vis,pathvis,check)) return true;
            }
            else if(pathvis[it]==1) return true;
        }
        pathvis[node]=0;
        check[node]=1;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cycle(i,graph,vis,pathvis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};