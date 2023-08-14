class Solution {
public:
    #define ll long long
    vector<vector<ll>> dp;
    ll solve(vector<int>&nums,int i,int prev){
        if(i>=nums.size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        ll ans=0;
        if(prev==0){
            ans=max(solve(nums,i+1,prev),nums[i]+solve(nums,i+1,1));
        }else{
            
            ans=max(solve(nums,i+1,prev),-nums[i]+solve(nums,i+1,0));
        }
        return dp[i][prev] = ans;
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<ll> (2,-1));
        return solve(nums,0,0);
    }
};