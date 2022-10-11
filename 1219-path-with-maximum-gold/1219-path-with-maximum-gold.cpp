class Solution {
public:
    int mx=0;
    void dfs(int i,int j,int n,int m,vector<vector<int>>&grid,int sum){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0 ) return;
        sum+=grid[i][j];
        mx=max(mx,sum);
        int temp = grid[i][j];
        grid[i][j]=0;
        dfs(i+1,j,n,m,grid,sum);
        dfs(i-1,j,n,m,grid,sum);
        dfs(i,j+1,n,m,grid,sum);
        dfs(i,j-1,n,m,grid,sum);
        grid[i][j]=temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    int sum=0;
                    dfs(i,j,n,m,grid,sum);
                }
            }
        }
        return mx;
    }
};