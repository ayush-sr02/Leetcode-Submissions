class Solution {
public:
    
    vector<int>dp;
    
    int helper(int n){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1)return dp[n];
        return dp[n]=helper(n-1)+helper(n-2);
    }
    
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        int x=helper(n);
        return x; 
    }
};