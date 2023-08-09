class Solution {
public:
    #define ll long long
    vector<vector<ll>> dp;
    
    ll solve(int i,int prev,vector<int>&nums,int x){
        if(i>=nums.size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        ll notPick = solve(i+1,prev,nums,x);
        ll pick = -1e12;
        if(nums[i]%2==0){
            if(prev) pick = nums[i]+solve(i+1,(nums[i]%2==0),nums,x);
            else pick = nums[i]+solve(i+1,(nums[i]%2==0),nums,x)-x;
        }
        else{
            if(prev) pick = nums[i]+solve(i+1,(nums[i]%2==0),nums,x)-x;
            else pick = nums[i]+solve(i+1,(nums[i]%2==0),nums,x);
        }
        return dp[i][prev]=max(pick,notPick);
    }
    
    long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        dp.resize(n,vector<ll>(2,-1));
        return solve(0,(nums[0]%2==0),nums,x);
    }
};