class Solution {
public:
    vector<int> dp;
    int solve(int n,vector<int>& cost, int i){
        if(i>n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int one = cost[i]+solve(n,cost,i+1);
        int two = cost[i]+solve(n,cost,i+2);
        return dp[i] = min(one,two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n,-1);
        int x=solve(n,cost,0);
        dp.resize(n,-1);
        int y=solve(n,cost,1);
        return min(x,y);
    }
};