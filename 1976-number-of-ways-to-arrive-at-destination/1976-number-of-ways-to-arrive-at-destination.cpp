class Solution {
public:
    #define ll long long
    #define pi pair<ll,ll>
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pi> adj[n];
        int mod = 1e9+7;
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<ll> dis(n,LONG_MAX),way(n,0);
        dis[0]=0;
        way[0]=1;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            ll node = pq.top().second;
            ll dist = pq.top().first;
            pq.pop();
            for(auto i:adj[node]){
                int adjNode = i.first;
                ll wt = i.second;
                if(wt+dist<dis[adjNode]){
                    dis[adjNode] = wt+dist;
                    pq.push({dis[adjNode],adjNode});
                    way[adjNode] = way[node];
                }else if(wt+dist==dis[adjNode]){
                    way[adjNode] = (way[adjNode]+way[node])%mod;
                }
            }
        }
        return way[n-1];
    }
};