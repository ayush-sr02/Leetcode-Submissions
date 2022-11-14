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
        if(b!=a){
            parent[b]=a;        //merge
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]){
                    merge(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i) ans++;
        }
        return n-ans;
    }
};