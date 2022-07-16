class Solution {
public:
    int solve(int target,vector<int>&coins,int i,vector<vector<int>>&dp){
        if(target==0){
            return 1;
        } 
        if(i==0){
            return target%coins[i]==0;
        }
        
        if(dp[i][target]!=-1) return dp[i][target];
        int notPick = solve(target,coins,i-1,dp);
        int pick=0;
        if(target>=coins[i]) pick = solve(target-coins[i],coins,i,dp);
        
        return dp[i][target] = pick+notPick;
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return solve(amount,coins,n-1,dp);
    }
};