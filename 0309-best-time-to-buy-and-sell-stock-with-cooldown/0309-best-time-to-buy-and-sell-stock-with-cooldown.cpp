class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i,int buy,vector<int>&prices){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(!buy){
            return dp[i][buy] = max(-prices[i]+solve(i+1,!buy,prices),solve(i+1,buy,prices));
        }else{
            return dp[i][buy] = max(prices[i]+solve(i+2,!buy,prices),solve(i+1,buy,prices));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n,vector<int> (2,-1));
        return solve(0,0,prices);
    }
};