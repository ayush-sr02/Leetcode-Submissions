class Solution {
public:
    vector<int> parent,size;
    
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u] = find(parent[u]);
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
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        parent.resize(n);
        iota(begin(parent),end(parent),0);
        size.resize(n,1);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                pq.push({dist,i,j});
            }
        }
        int count=0;
        while(!pq.empty() and count!=n-1){
            auto top = pq.top();
            pq.pop();
            int dist = top[0],x = top[1],y = top[2];
            x=find(x);
            y=find(y);
            if(x!=y){
                count++;
                merge(x,y);
                ans+=dist;
            }
        }
        return ans;
    }
};