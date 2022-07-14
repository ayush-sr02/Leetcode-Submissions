class Solution {
public:
    
    int solve(vector<int>&coins,int target,int i,vector<vector<int>>&dp){
        if(i==0) {
            if(target%coins[i]==0) return target/coins[i];
            return 1e9;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notPick = solve(coins,target,i-1,dp);
        int pick = 1e9;
        if(coins[i]<=target) pick = 1+solve(coins,target-coins[i],i,dp);
        return dp[i][target] = min(notPick,pick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans = solve(coins,amount,n-1,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};