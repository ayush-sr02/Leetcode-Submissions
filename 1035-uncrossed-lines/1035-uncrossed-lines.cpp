class Solution {
public:
    
    int solve(int i,int j,vector<int>&n1,vector<int>&n2,vector<vector<int>>&dp){
        if(i<0 or j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(n1[i]==n2[j]) return dp[i][j] = 1+solve(i-1,j-1,n1,n2,dp);
        return dp[i][j] = max(solve(i-1,j,n1,n2,dp),solve(i,j-1,n1,n2,dp));
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(n-1,m-1,nums1,nums2,dp);
    }
};