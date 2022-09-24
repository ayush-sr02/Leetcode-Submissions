class Solution {
public:
    int solve(int n,int m,vector<vector<int>>&dp){
        if(n==0 and m==0) return 1;
        if(n<0 or m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int left = solve(n-1,m,dp);
        int right = solve(n,m-1,dp);
        return dp[n][m] = left+right;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(m-1,n-1,dp);
    }
};