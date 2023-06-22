class Solution {
public:
    
    vector<vector<int>> dp;
    
    int solve(vector<int>&prices,int fee,int i,int buy){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        int profit=0;
        if(buy){
            profit = max(-prices[i]+solve(prices,fee,i+1,0),solve(prices,fee,i+1,1));
        }
        else{
            profit = max(prices[i]-fee+solve(prices,fee,i+1,1),solve(prices,fee,i+1,0));
        }
        
        return dp[i][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int> (2,-1));
        return solve(prices,fee,0,1);
    }
};