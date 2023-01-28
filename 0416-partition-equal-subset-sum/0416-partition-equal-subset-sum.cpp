class Solution {
public:
    
    int solve(vector<int>&nums,vector<vector<int>>&dp,int sum,int i){
        if(i<0) return 0;
        if(i==0) return sum==nums[i];
        if(dp[i][sum]!=-1) return dp[i][sum];
        int notPick = solve(nums,dp,sum,i-1);
        int pick=0;
        if(sum>=nums[i]) pick = solve(nums,dp,sum-nums[i],i-1);
        return dp[i][sum] = pick or notPick;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(begin(nums),end(nums),0);
        if(sum%2!=0) return false;
        sum/=2;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return solve(nums,dp,sum,n-1);
    }
};