class Solution {
public:
    
    int solve(vector<int>&nums,int target,vector<int> &dp){
        if(target<0) return 0;
        else if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        
        int valid=0;
        for(auto i:nums){
            if(target-i>=0){
                valid+=solve(nums,target-i,dp);
            }
        }
        
        return dp[target]=valid;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        int ans = solve(nums,target,dp);
        return ans;
    }
};