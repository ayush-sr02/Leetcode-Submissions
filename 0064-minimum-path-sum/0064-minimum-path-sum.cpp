class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if (i<0 or j<0) return 1e5;
        if(i==0 and j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = grid[i][j]+solve(i-1,j,grid,dp);
        int left = grid[i][j]+solve(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};