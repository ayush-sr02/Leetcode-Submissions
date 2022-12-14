class Solution {
public:
    
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i==0) return nums[i];
        if(dp[i]!=-1) return dp[i];
        int notPick = solve(i-1,nums,dp);
        int pick = nums[i];
        if(i>1) pick += solve(i-2,nums,dp);
        return dp[i] = max(pick,notPick);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(n-1,nums,dp);
    }
};