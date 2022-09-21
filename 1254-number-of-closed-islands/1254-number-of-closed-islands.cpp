class Solution {
public:
    
    void dfs(vector<vector<int>>&grid,int i,int j,int n,int m){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==1) return;
        grid[i][j]=1;
        dfs(grid,i+1,j,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j+1,n,m);
        dfs(grid,i,j-1,n,m);
    }
    
    void dfsZero(vector<vector<int>>&grid,int i,int j,int n,int m){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==1) return;
        grid[i][j]=1;
        dfsZero(grid,i+1,j,n,m);
        dfsZero(grid,i-1,j,n,m);
        dfsZero(grid,i,j+1,n,m);
        dfsZero(grid,i,j-1,n,m);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or i==n-1 or j==m-1){
                    dfsZero(grid,i,j,n,m);
                }
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};