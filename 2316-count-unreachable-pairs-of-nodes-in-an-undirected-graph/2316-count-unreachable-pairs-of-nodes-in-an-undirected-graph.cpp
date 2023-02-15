class Solution {
public:
    #define ll long long
    vector<int> parent,size;
    
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v) return ;
        if(size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }
        else{
            parent[v]=u;
            size[u]+=size[v];
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        ll ans=0;
        parent.resize(n);
        iota(begin(parent),end(parent),0);
        size.resize(n,1);
        for(auto i:edges){
            int x=i[0];
            int y=i[1];
            int xx=find(x);
            int yy=find(y);
            if(xx==yy) continue;
            else merge(x,y);
        }
        unordered_map<ll,ll> mp;
        for(int i=0;i<parent.size();i++){
            mp[find(i)]++;
        }
        for(auto i:mp){
            ans+=(1LL)*((n-i.second)*i.second);
        }
        
        return ans/2;
    }
};