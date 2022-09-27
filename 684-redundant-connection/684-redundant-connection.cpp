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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        vector<int> ans;
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto i:edges){
            int a=i[0];
            int b=i[1];
            if(find(a)==find(b)) return{a,b};
            else{
                merge(a,b);
            }
        }
        
        return {};
        
    }
};