class Solution {
public:
    #define pi pair<int,int> 
    vector<pair<int,int>> movement = {{0,1},{0,-1},{-1,0},{1,0}};
    bool valid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> pq;
        int ans=0;
        vector<vector<int>> dis(n,vector<int> (m,1e9));
        dis[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            int dist=pq.top().first;
            pq.pop();
            if(x==n-1 and y==m-1) return dist;
            for(auto i:movement){
                int xd = x+i.first;
                int yd = y+i.second;
                if(valid(xd,yd,n,m)){
                    int temp = max(abs(grid[xd][yd]-grid[x][y]),dist);
                    if(temp<dis[xd][yd]){
                        dis[xd][yd] = temp;
                        pq.push({dis[xd][yd],{xd,yd}});
                    }
                }
            }
        }
        
        return ans;
    }
};