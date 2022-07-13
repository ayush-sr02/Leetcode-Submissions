class Solution {
public:
    
    int solve(int i,int j1,int j2,int m,int n,vector<vector<vector<int>>> &dp,vector<vector<int>> &grid){
        if(j1<0 || j2<0 || j1>=n || j2>=n) return -1e9;
        
        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int mx=-1e9;
        for(int jj1=-1;jj1<=1;jj1++){
            for(int jj2=-1;jj2<=1;jj2++){
                int val=0;
                if(j1==j2) val=grid[i][j1];
                else val=grid[i][j1]+grid[i][j2];
                val+=solve(i+1,j1+jj1,j2+jj2,m,n,dp,grid);
                mx=max(mx,val);
            }
        }
        return dp[i][j1][j2] = mx;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (n,-1)));
        return solve(0,0,n-1,m,n,dp,grid);
    }
};