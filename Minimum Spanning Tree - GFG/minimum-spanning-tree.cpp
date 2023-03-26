//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	#define pi pair<int,int> 
    vector<int> parent,size;
    
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v) return ;
        if(size[u]>v){
            parent[v]=u;
            size[u]+=size[v];
        }else{
            parent[u]=v;
            size[v]+=size[u];
        }
    }
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int sum=0;
        parent.resize(V);
        iota(parent.begin(),parent.end(),0);
        size.resize(V,1);
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],{i,it[0]}});
            }
        }
        sort(begin(edges),end(edges));
        for(auto i:edges){
            int wt=i.first;
            int node = i.second.first;
            int adjNode = i.second.second;
            int x = find(node);
            int y = find(adjNode);
            if(x==y) continue;
            else{
                sum+=wt;
                merge(node,adjNode);
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends