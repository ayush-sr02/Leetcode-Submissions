class Solution {
public:
    
    vector<pair<int,int>> movement = {{-1,0},{1,0},{0,1},{0,-1}};
    
    bool valid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }
        int ans=0;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int temp = q.front().second;
            q.pop();
            ans=max(ans,temp);
            for(auto it:movement){
                int xd = x+it.first;
                int yd = y+it.second;
                if(valid(xd,yd,n,m) and grid[xd][yd]==1){
                    q.push({{xd,yd},temp+1});
                    grid[xd][yd]=2;
                }
            }
        }
        
        for(auto i:grid){
            for(auto j:i){
                if(j==1) return -1;
            }
        }
        
        return ans;
    }
};