class Solution {
public:
    
    vector<vector<int>>dp;
    
    bool helper(int ind,int sum,vector<int>&nums,int target){
        if(ind>=nums.size()) return sum==target;
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        bool pick=false;
        if(sum+nums[ind]<=target){
            pick=helper(ind+1,sum+nums[ind],nums,target);
        }
        bool notpick=helper(ind+1,sum,nums,target);
        return dp[ind][sum]=pick or notpick;
    }
    
    bool canPartition(vector<int>& nums) {
        int x=accumulate(nums.begin(),nums.end(),0);
        dp.resize(nums.size(),vector<int>(x/2+1,-1));
        if(x&1) return false;
        return helper(0,0,nums,x/2);
    }
};