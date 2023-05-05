class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& info) {
        int ans=0;
        vector<vector<int>> adj(n);
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1) adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({headID,0});
        vector<int> vis(n,0);
        vis[headID]=1;
        while(!q.empty()){
            int node = q.front().first;
            int cost = q.front().second;
            q.pop();
            ans=max(ans,cost);
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push({it,cost+info[node]});
                    vis[it]=1;
                }
            }
        }
        return ans;
    }
};