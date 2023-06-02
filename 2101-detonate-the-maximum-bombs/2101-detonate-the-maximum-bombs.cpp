class Solution {
public:
    #define ll long long
    void dfs(int node,vector<int>&vis,vector<int> adj[],int &cnt){
        vis[node]=1;
        cnt++;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,vis,adj,cnt);  
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        int ans=0;
        vector<int> adj[n];
        for(int i=0;i<bombs.size();i++){
            ll a=bombs[i][0],b=bombs[i][1],c=bombs[i][2];
            for(int j=i+1;j<n;j++){
                ll d=bombs[j][0],e=bombs[j][1],f=bombs[j][2];
                double dist = sqrt(abs(d-a)*abs(d-a)+abs(e-b)*abs(e-b));
                if(dist<=c) adj[i].push_back(j);
                if(dist<=f) adj[j].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            int cnt=0;
            dfs(i,vis,adj,cnt);
            ans=max(ans,cnt);
        }
        return ans;
    }
};