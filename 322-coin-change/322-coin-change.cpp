class Solution {
public:
    
    int solve(int i,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(i==0){
            if(target%coins[i]==0) return target/coins[i];
            return 1e9;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notPick = solve(i-1,target,coins,dp);
        int pick = 1e9;
        if(target>=coins[i]) pick = 1+solve(i,target-coins[i],coins,dp);
        return dp[i][target] = min(pick,notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        int ans = solve(n-1,amount,coins,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};