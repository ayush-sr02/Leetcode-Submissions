class Solution {
public:
    vector<int> dp;
    int solve(int i,vector<int>&nums){
        if(i>=nums.size()) return 1e5;
        if(i==nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=1e5;
        for(int j=i+1;j<nums.size() and j<=i+nums[i];j++){
            ans=min(ans,1+solve(j,nums));
        }
        return dp[i]=ans;
    }
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        return solve(0,nums);
    }
};