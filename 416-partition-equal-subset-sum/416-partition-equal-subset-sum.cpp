class Solution {
public:
    
    int solve(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(i<0) return 0;
        if(i==0) return nums[i]==target;
        if(dp[i][target]!=-1) return dp[i][target];
        int notPick = solve(i-1,target,nums,dp);
        int pick = 0;
        if(target>=nums[i]) pick = solve(i-1,target-nums[i],nums,dp);
        return dp[i][target] = pick|notPick;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums) sum+=i;
        if(sum%2!=0) return false;
        int n=nums.size();
        sum/=2;
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return solve(n-1,sum,nums,dp);
    }
};