class Solution {
public:
    int t;
    
    int solve(int i,int sum,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(i<0) return abs(t-sum);
        if(dp[sum][i]!=-1) return dp[sum][i];
        int temp = 1e5;
        for(int col=0;col<mat[0].size();col++){
            temp = min(temp,solve(i-1,sum+mat[i][col],mat,dp));
            if(temp==0){
                return dp[sum][i]=0;
            }
        }
        return dp[sum][i] = temp;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        t=target;
        int n=mat.size(),m=mat[0].size();
        int sum=0,row=n-1;
        vector<vector<int>> dp(5000,vector<int> (71,-1));
        return solve(row,sum,mat,dp);
    }
};