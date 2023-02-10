//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  #define pi pair<int,int>
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pi> adj[n+1];
        vector<int> ans;
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        vector<int> dis(n+1,1e9),par(n+1);
        for(int i=0;i<=n;i++) par[i]=i;
        dis[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto i:adj[node]){
                int adjNode = i.first;
                int wt = i.second;
                if(dist+wt<dis[adjNode]){
                    dis[adjNode] = dist+wt;
                    pq.push({dis[adjNode],adjNode});
                    par[adjNode] = node;
                }
            }
        }
        if(dis[n]==1e9) return {-1};
        int i=n;
        while(par[i]!=i){
            ans.push_back(i);
            i=par[i];
        }
        ans.push_back(1);
        reverse(begin(ans),end(ans));
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends