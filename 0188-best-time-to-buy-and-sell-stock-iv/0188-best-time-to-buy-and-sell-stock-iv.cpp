class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    int solve(int i,int buy,int t,vector<int>&prices){
        if(i==prices.size() or t<0) return 0;
        if(dp[i][buy][t]!=-1) return dp[i][buy][t];
        if(!buy){
            return dp[i][buy][t] =  max(-prices[i]+solve(i+1,!buy,t-1,prices),solve(i+1,buy,t,prices));
        }else{
            return dp[i][buy][t] = max(prices[i]+solve(i+1,!buy,t,prices),solve(i+1,buy,t,prices));
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        dp.resize(n,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return solve(0,0,k,prices);
    }
};