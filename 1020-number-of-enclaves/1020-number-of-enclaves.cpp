class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int i,int j,int n,int m){
        if(i<0 or j<0 or i>=n or j>=m or vis[i][j]) return;
        if(grid[i][j]==0) return;
        vis[i][j] = 1;
        dfs(grid,vis,i+1,j,n,m);
        dfs(grid,vis,i-1,j,n,m);
        dfs(grid,vis,i,j+1,n,m);
        dfs(grid,vis,i,j-1,n,m);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                if(!vis[0][j]){
                    dfs(grid,vis,0,j,n,m);
                }
            }
            if(grid[n-1][j]==1){
                if(!vis[n-1][j]){
                    dfs(grid,vis,n-1,j,n,m);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                if(!vis[i][0]){
                    dfs(grid,vis,i,0,n,m);
                }
            }
            if(grid[i][m-1]==1){
                if(!vis[i][m-1]){
                    dfs(grid,vis,i,m-1,n,m);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and grid[i][j]==1) ans++; 
            }
        }
        return ans;
    }
};