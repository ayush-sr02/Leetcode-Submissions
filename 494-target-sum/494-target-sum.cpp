class Solution {
public:
    
    int solve(vector<int>&nums,int target,vector<vector<int>>&dp,int i,int val){
        if(i<0){
            if(val==target) return 1;
            else return 0;
        }
        if(val<0){
            if(dp[i][val+1001]!=-1) return dp[i][val+1001];
        }
        else if(dp[i][val]!=-1) return dp[i][val];
        int cnt=0;        
        cnt += solve(nums,target,dp,i-1,val+nums[i]);
        cnt += solve(nums,target,dp,i-1,val-nums[i]);
        if(val<0) return dp[i][val+1001] = cnt;
        return dp[i][val] = cnt;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(21,vector<int> (2002,-1));
        return solve(nums,target,dp,n-1,0);
    }
};