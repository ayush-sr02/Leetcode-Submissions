class Solution {
public:
    
    bool solve(vector<int> &nums,int target,int i,vector<vector<int>> &dp){
        if(i==0) return nums[i]==target;
        if(target==0) return true;
        if(dp[i][target]!=-1) return dp[i][target];
        bool notPick = solve(nums,target,i-1,dp);
        bool pick = false;
        if(target>=nums[i]) pick = solve(nums,target-nums[i],i-1,dp);
        return dp[i][target] = pick||notPick;
    }    
    
    bool canPartition(vector<int>& nums) {
        int s=accumulate(nums.begin(),nums.end(),0);
        if(s%2!=0) return false;
        int n=nums.size();
        vector<vector<int>> dp(201,vector<int> (10001,-1));
        return solve(nums,s/2,n-1,dp);
    }
};