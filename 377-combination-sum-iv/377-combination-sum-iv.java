class Solution {
    public int solve(int[] nums,int target,int[] dp){
        if(target<0) return 0;
        else if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];

        int valid=0;
        for(int i=0;i<nums.length;i++){
            if(target-nums[i]>=0){
                valid+=solve(nums,target-nums[i],dp);
            }
        }
        return dp[target]=valid;
    }

    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target+1];
        Arrays.fill(dp,-1);
        int ans=solve(nums,target,dp);
        return ans;
    }
}