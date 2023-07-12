class Solution {
public:
    vector<int> dp;
    int solve(int i,vector<int>&cost){
        if(i==cost.size()-1) return cost[i];
        if(dp[i]!=-1) return dp[i];
        int one = cost[i]+solve(i+1,cost);
        int two = cost[i];
        if(i<cost.size()-2) two+=solve(i+2,cost);
        return dp[i] = min(one,two);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n,-1);
        int zero = solve(0,cost);
        dp.resize(n,-1);
        int one = solve(1,cost);
        return min(zero,one);
    }
};