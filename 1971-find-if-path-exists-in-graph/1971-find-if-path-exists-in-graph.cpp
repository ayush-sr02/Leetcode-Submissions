class Solution {
public:
    vector<int> parent;
    int find(int a){
        if(parent[a]==a) return a;
        return parent[a] = find(parent[a]);     //path optimization
    }
    
    void merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            parent[b]=a;    //merge step
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto i:edges){
            int a=find(i[0]);
            int b=find(i[1]);
            if(a==b) continue;
            else merge(a,b);
        }
        return find(source)==find(destination);
    }
};