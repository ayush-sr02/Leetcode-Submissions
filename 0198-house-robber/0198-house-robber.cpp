class Solution {
public:
    vector<int> dp;
    int solve(vector<int>&nums,int i,int n){
        if(i>n-1) return 0;
        if(i==n-1) return nums[i];
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+solve(nums,i+2,n);
        int notPick=solve(nums,i+1,n);
        return dp[i]=max(pick,notPick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        return solve(nums,0,n);
    }
};