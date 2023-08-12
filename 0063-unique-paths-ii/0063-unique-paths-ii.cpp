class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i>=grid.size() or  j>=grid[0].size() or grid[i][j]==1) return 0;
        if(i==grid.size()-1 and j==grid[0].size()-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = solve(i,j+1,grid);
        int down = solve(i+1,j,grid);
        return dp[i][j]=right+down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        dp.resize(n,vector<int> (m,-1));
        return solve(0,0,grid);
    }
};