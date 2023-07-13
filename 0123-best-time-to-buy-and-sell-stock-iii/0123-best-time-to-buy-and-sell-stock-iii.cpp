class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    int solve(vector<int> &prices,int i,int buy,int t){
        if(i==prices.size() or t<0) return 0;
        if(dp[i][buy][t]!=-1) return dp[i][buy][t];
        
        if(!buy){
            return dp[i][buy][t] = max(-prices[i]+solve(prices,i+1,!buy,t-1),solve(prices,i+1,buy,t));
        }else{
            return dp[i][buy][t] = max(prices[i]+solve(prices,i+1,!buy,t),solve(prices,i+1,buy,t));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n,vector<vector<int>> (2,vector<int> (3,-1)));
        return solve(prices,0,0,2);
    }
};