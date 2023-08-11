class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i,int target,vector<int>&coins){
        if(target==0) return 1;
        if(i>=coins.size()) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        int notPick = solve(i+1,target,coins);
        int pick=0;
        if(target>=coins[i]) pick = solve(i,target-coins[i],coins);
        return dp[i][target] = pick+notPick;
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        sort(begin(coins),end(coins));
        dp.resize(n,vector<int> (amount+1,-1));
        return solve(0,amount,coins);
    }
};