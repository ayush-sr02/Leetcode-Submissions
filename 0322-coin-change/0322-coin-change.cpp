class Solution {
public:
    int solve(vector<int>&coins, int i,int n,int t, vector<vector<int>> &dp){
        if(t==0) return 0;
        if(i>=n){
            if(t==0) return 0;
            return 1e9;
        }
        if(dp[i][t]!=-1) return dp[i][t];
        int notPick = solve(coins, i+1, n, t, dp);
        int pick = 1e9;
        if(coins[i]<=t) pick = 1 + solve(coins, i, n, t-coins[i], dp);
        return dp[i][t] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        sort(rbegin(coins), rend(coins));
        int ans=solve(coins, 0, n, amount, dp);
        return ans==1e9?-1:ans;
    }
};