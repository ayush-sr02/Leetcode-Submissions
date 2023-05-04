class Solution {
public:
    
    int find(int u,vector<int> &parent){
        if(parent[u]==u) return u;
        return parent[u] = find(parent[u],parent);
    }
    
    void merge(int u,int v,vector<int> &parent,vector<int> &size){
        u=find(u,parent);
        v=find(v,parent);
        if(u==v) return;
        if(size[u]>size[v]){
            parent[v] = u;
            size[u]+=size[v];
        }else{
            parent[u] = v;
            size[v]+=size[u];
        }
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(rbegin(edges),rend(edges));
        // for(auto i:edges){
        //     for(auto j:i) cout<<j<<" ";
        //     cout<<endl;
        // }
        int alice=1,bob=1;
        int redundant=0;
        vector<int> a(n+1),sizeA(n+1,1);
        vector<int> b(n+1),sizeB(n+1,1);
        iota(begin(a),end(a),0);
        iota(begin(b),end(b),0);
        for(auto i:edges){
            if(i[0]==3){
                bool al=false,bo=false;
                int x1 = find(i[1],a);
                int y1 = find(i[2],a);
                if(x1==y1){
                    al=true;
                }
                int x2 = find(i[1],b);
                int y2 = find(i[2],b);
                if(x2==y2){
                    bo=true;
                }
                if(al and bo) redundant++;
                else{
                    merge(i[1],i[2],a,sizeA);
                    merge(i[1],i[2],b,sizeB);
                    alice++,bob++;
                }
               
            }else if(i[0]==1){
                int x = find(i[1],a);
                int y = find(i[2],a);
                if(x==y){
                    redundant++;
                }
                else merge(x,y,a,sizeA),alice++;
            }
            else{
                int x = find(i[1],b);
                int y = find(i[2],b);
                if(x==y){
                    redundant++;
                }
                else merge(x,y,b,sizeB),bob++;
            }
        }
        // cout<<alice<<" "<<bob<<endl;
        return (alice==bob and alice>=n)?redundant:-1;
    }
};