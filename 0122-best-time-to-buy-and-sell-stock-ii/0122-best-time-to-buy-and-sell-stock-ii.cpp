class Solution {
public:
    
    int solve(vector<int> &prices,int i,vector<vector<int>>&dp,int buy){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(!buy){
            return dp[i][buy] = max(-prices[i]+solve(prices,i+1,dp,!buy),solve(prices,i+1,dp,buy));
        }else{
            return dp[i][buy]=  max(prices[i]+solve(prices,i+1,dp,!buy),solve(prices,i+1,dp,buy));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return solve(prices,0,dp,0);
    }
};