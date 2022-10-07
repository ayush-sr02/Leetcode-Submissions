class Solution {
public:
    
    vector<int> parent;
    
    int find(int a){
        if(parent[a]==a) return a;
        return parent[a] = find(parent[a]);     //path compression.
    }
    
    void merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            parent[b]=a;    //merge.
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        int redundant = 0;
        for(int i=0;i<connections.size();i++){
            int a=find(connections[i][0]);
            int b=find(connections[i][1]);
            // cout<<a<<" "<<b<<endl;
            
            if(a==b){
                continue;
            }
            else{
                merge(a,b);
                redundant++;
            }
            // cout<<parent[a]<<" "<<parent[b]<<endl;
        }
        // cout<<redundant;
        if(connections.size()<n-1) return -1;
        else return n-redundant-1;
    }
};