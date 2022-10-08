class Solution {
public:
    vector<int> parent;
    int find(int a){
        if(parent[a]==a) return a;
        return parent[a] = find(parent[a]);     //path compression
    }
    
    void merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            parent[b]=a;        //merge
        }
    }
    
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> store;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) store.push_back({i,j});
            }
        }
        int size = store.size();
        int ans=0;
        
        parent.resize(size);
        iota(parent.begin(),parent.end(),0);
        for(int i=0;i<size-1;i++){
            for(int j=i+1;j<size;j++){
                if(store[i][0]==store[j][0] or store[i][1]==store[j][1]){
                    merge(i,j);
                }
            }
        }
        map<int,int> mp;
        for(int i=0;i<parent.size();i++){
            mp[find(parent[i])]++;
        }
        for(auto i:mp){
            if(i.second>1) ans+=i.second;
        }
        return ans;
    }
};