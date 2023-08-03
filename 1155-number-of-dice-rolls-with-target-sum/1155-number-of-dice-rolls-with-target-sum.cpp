class Solution {
public:
    int mod = 1e9+7;
    int solve(int n,int k,int target,vector<vector<int>> &dp){
        if(target==0 and n==0) return 1;
        if(n==0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int ans=0;
        for(int j=1;j<=k;j++){
            if(j<=target) ans = (ans%mod+solve(n-1,k,target-j,dp)%mod)%mod;
        }
        return dp[n][target]=ans%mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return solve(n,k,target,dp);
    }
};