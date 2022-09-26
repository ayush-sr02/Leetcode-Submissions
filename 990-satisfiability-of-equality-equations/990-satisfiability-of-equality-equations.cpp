class Solution {
public:
    //Implementation of DSU.
    vector<int> parent;
    int find(int v){
        if(parent[v]==v){
            return v;
        }
        return parent[v] = find(parent[v]); //path compression step.
    }
    
    void merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            parent[b]=a;
        }
    }
    
    bool equationsPossible(vector<string>& eq) {
        parent.resize(26);
        
        for(int i=0;i<26;i++){  //make function of DSU
            parent[i]=i;
        }
        
        for(auto i:eq){
            if(i[1]=='='){
                merge(i[0]-'a',i[3]-'a');
            }
        }
        
        for(auto i:eq){
            if(i[1]=='!'){
                if(find(i[0]-'a')==find(i[3]-'a')) return false;
            }
        }
        
        return true;
        
    }
};