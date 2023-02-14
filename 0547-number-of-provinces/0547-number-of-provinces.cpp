class Solution {
public:
    vector<int> parent,size;
    
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u] = find(parent[u]);     // path compression
    }
    
    void merge(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v) return;
        if(size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }else{
            parent[v]=u;
            size[u]+=size[v];
        }
    }
    
    int findCircleNum(vector<vector<int>>& c) {
        int n=c.size();
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(c[i][j]==1){
                    merge(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            if(parent[i]==i) cnt++;
        
        return cnt;
    }
};