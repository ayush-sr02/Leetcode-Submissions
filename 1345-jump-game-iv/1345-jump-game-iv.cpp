class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<int> vis(n,0);
        vis[0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int node = q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(node==n-1) return cnt;
            if(node+1<n and !vis[node+1]){
                q.push({node+1,cnt+1});
                vis[node+1]=1;
            }
            if(node-1>=0 and !vis[node-1]){
                q.push({node-1,cnt+1});
                vis[node-1]=1;
            }
            for(auto it:mp[arr[node]]){
                if(!vis[it] and it!=node){
                    q.push({it,cnt+1});
                    vis[it]=1;
                }
            }
            // clear the map to avoid repetitions
            mp[arr[node]].clear();
        }
        return -1;
    }
};