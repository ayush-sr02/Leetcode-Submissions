class Solution {
public:
    
    int solve(int i,int target,vector<int>&nums,vector<vector<int>>&dp,int cur){
        if(i<0){
            return target==cur;
        }
        if(dp[i][cur]!=-1) return dp[i][cur];
        return dp[i][cur] = solve(i-1,target,nums,dp,cur|nums[i]) + solve(i-1,target,nums,dp,cur);
    } 
    
    int countMaxOrSubsets(vector<int>& nums) {
        int cur=0;
        for(int i=0;i<nums.size();i++){
            cur|=nums[i];
        }
        int n=nums.size();
        vector<vector<int>> dp(nums.size()+1,vector<int> (cur+1,-1));
        return solve(nums.size()-1,cur,nums,dp,0);
    }
};