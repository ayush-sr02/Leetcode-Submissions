class Solution {
public: 
    
    int solve(vector<int>&coins,vector<vector<int>>&dp,int i,int target){
        if(i==0){
            if(target%coins[i]==0) return target/coins[i];
            return 1e9;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        
        int notPick = solve(coins,dp,i-1,target);
        int pick = 1e9;
        if(target>=coins[i]) pick = 1+solve(coins,dp,i,target-coins[i]);
        return dp[i][target] = min(pick,notPick);
    }
    
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        sort(begin(coins),end(coins));
        vector<vector<int>> dp(n,vector<int> (amt+1,-1));
        int x=solve(coins,dp,n-1,amt);
        return x==1e9?-1:x;
    }
};