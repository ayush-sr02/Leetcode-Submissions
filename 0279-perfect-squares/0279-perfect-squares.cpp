class Solution {
public:
    
    int solve(int i,vector<int>&dp){
        if(i<=1) return i;
        if(dp[i]!=-1) return dp[i];
        int ans=1e9;
        for(int j=i;j>=1;j--){
            if(j*j<=i){
                int temp = 1+solve(i-j*j,dp);
                ans=min(ans,temp);
                dp[i]=ans;
            }
        }
        return dp[i]=ans;
    }
    
    int numSquares(int n) {
        
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};