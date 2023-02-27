class Solution {
public:
    vector<vector<int>> movement = {{0,1},{0,-1},{1,0},{-1,0}};   
    
    bool valid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        // coordinates,time
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }
        
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int time=q.front().second;
            ans=max(ans,time);
            q.pop();
            for(auto i:movement){
                int xd=x+i[0];
                int yd=y+i[1];
                if(valid(xd,yd,n,m) and grid[xd][yd]==1){
                    q.push({{xd,yd},time+1});
                    grid[xd][yd]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};