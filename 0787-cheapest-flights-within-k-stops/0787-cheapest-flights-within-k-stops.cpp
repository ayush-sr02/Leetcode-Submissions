class Solution {
public:
    #define pi pair<int,int> 
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        int ans=0;
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        queue<pair<int,pi>> q;          // store in the order {stop,{node,distance}}
        q.push({0,{src,0}});
        vector<int> dis(n,1e9);
        dis[src]=0;
        
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();
            if(stop>k) continue;        // no more than k stops are allowed
            for(auto it:adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(wt+dist<dis[adjNode] and stop<=k){
                    dis[adjNode] = wt+dist;
                    q.push({stop+1,{adjNode,dis[adjNode]}});
                } 
            }
        }
        return dis[dst]==1e9?-1:dis[dst];
    }
};