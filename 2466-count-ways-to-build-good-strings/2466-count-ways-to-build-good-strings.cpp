class Solution {
public:
    int mod = 1e9+7;
    vector<int> dp;
    
    int solve(int i,int low,int high,int zero,int one){
        if(i==high) return 1;
        if(i>high) return 0;
        if(dp[i]!=-1) return dp[i];
        int count=0;
        if(i>=low and i<=high) count=1;
        count=(count+solve(i+zero,low,high,zero,one)%mod);
        count=(count+solve(i+one,low,high,zero,one)%mod);
        return dp[i] = count%mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high+1,-1);
        return solve(0,low,high,zero,one);
    }
};