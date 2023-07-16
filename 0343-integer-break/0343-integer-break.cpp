class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int mx=n;
        for(int i=1;i<=n;i++){
            int temp = max(mx,i*solve(n-i,dp));
            mx=max(mx,temp);
        }
        return dp[n]=mx;
    }
    
    int integerBreak(int n) {
        if(n<4) return n-1;
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};