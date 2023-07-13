class Solution {
public:
    
    int solve(int i,vector<int>&dp){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=1e5;
        for(int x=i;x>0;x--){
            if(x*x<=i){
                int temp = 1+solve(i-x*x,dp);
                ans=min(ans,temp);
            }
        }
        return dp[i]=ans;
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};