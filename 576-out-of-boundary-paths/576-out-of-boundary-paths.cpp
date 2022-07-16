class Solution {
public:
    int mod = 1000000007;
    int dfs(int row,int col,vector<vector<vector<int>>>&dp,int t,int m,int n){
        if(row<0 || col<0 || row>=m || col>=n) return 1;
        if(t<=0) return 0;
        if(dp[row][col][t]!=-1) return dp[row][col][t];
        long tt=0;
        tt+= dfs(row,col-1,dp,t-1,m,n)%mod;
        tt+= dfs(row,col+1,dp,t-1,m,n)%mod;
        tt+= dfs(row+1,col,dp,t-1,m,n)%mod;
        tt+= dfs(row-1,col,dp,t-1,m,n)%mod;
        return dp[row][col][t] = tt%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int row, int col) {
        vector<vector<vector<int>>> dp(51,vector<vector<int>> (51,vector<int> (51,-1)));
        return dfs(row,col,dp,maxMove,m,n)%mod;
    }
};