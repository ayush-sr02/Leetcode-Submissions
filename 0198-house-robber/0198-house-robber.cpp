class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp){
        if(i==0) return nums[i];
        if(dp[i]!=-1) return dp[i];
        int notPick=solve(nums,i-1,dp);
        int pick=nums[i];
        if(i>1) pick+=solve(nums,i-2,dp);
        return dp[i] = max(pick,notPick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.size(),-1);
        return solve(nums,n-1,dp);
    }
};