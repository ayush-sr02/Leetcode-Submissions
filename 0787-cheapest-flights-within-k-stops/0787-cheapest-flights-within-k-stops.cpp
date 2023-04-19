class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        queue<pair<pair<int,int>,int>> pq;
        vector<int> dis(n,1e9);
        pq.push({{0,0},src});
        dis[src]=0;
        
        while(!pq.empty()){
            int step = pq.front().first.first;
            int distance = pq.front().first.second;
            int node = pq.front().second;
            pq.pop();
            if(step>k) continue;
            
            for(auto it:adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(distance+wt<dis[adjNode]){
                    dis[adjNode] = distance+wt;
                    pq.push({{step+1,dis[adjNode]},adjNode});
                }
            }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};