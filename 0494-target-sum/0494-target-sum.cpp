class Solution {
public:
    
    //shift the index of target to keep it positive.
    int solve(int i,int target,int sum,vector<int> &nums,vector<vector<int>>&dp){
        if(i<0) return target==sum;
        if(dp[i][sum+1000]!=-1) return dp[i][sum+1000];
        int neg = solve(i-1,target,sum-nums[i],nums,dp);
        int pos = solve(i-1,target,sum+nums[i],nums,dp);
        return dp[i][sum+1000] = (neg+pos);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (20001,-1));
        int sum=0;
        return solve(n-1,target,sum,nums,dp);
    }
};