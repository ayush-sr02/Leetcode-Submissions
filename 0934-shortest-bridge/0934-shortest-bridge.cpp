class Solution {
public:
    
    vector<pair<int,int>> movement = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool valid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    //dfs to change one of the graph from 1s to 101s since max(n) = 100
    void dfs(int i,int j,int n,int m,vector<vector<int>>&grid){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]!=1) return;
        grid[i][j]=101;
        dfs(i+1,j,n,m,grid);
        dfs(i-1,j,n,m,grid);
        dfs(i,j+1,n,m,grid);
        dfs(i,j-1,n,m,grid);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,n,m,grid);  //change one of the graph then put the other graph indices in queue
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }

        //multi source bfs to find min dist.
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) q.push({{i,j},0});
            }
        }
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int len = q.front().second;
            q.pop();
            for(auto i:movement){
                int xd = x+i.first;
                int yd = y+i.second;
                if(valid(xd,yd,n,m)==true){
                    if(grid[xd][yd]==101) return len;
                    else if(grid[xd][yd]==0){
                        q.push({{xd,yd},len+1});
                        grid[xd][yd]=1;
                    }
                }
            }
        }
        return ans;
    }
};