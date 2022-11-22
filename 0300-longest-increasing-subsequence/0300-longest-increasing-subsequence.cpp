class Solution {
public:
    
    int solve(int i,int prev,vector<vector<int>>&dp,vector<int>&nums){
        if(i>=nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int notPick = solve(i+1,prev,dp,nums);
        int pick = 0;
        if(prev==-1 or nums[i]>nums[prev]) pick = 1+solve(i+1,i,dp,nums);
        return dp[i][prev+1] = max(pick,notPick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,dp,nums);
    }
};