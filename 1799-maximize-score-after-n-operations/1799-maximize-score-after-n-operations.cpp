class Solution {
public:
    int n;
    int solve(vector<int>&nums,vector<int>&dp,int mask){
        if(mask==(1<<n)-1) return 0;
        if(dp[mask]!=-1) return dp[mask];
        int setbit = __builtin_popcount(mask)/2+1;
        int mx = -1e9;
        for(int i=0;i<n;i++){
            if((mask&(1<<i))==0){
                for(int j=i+1;j<n;j++){
                    if((mask&(1<<j))==0){
                        int gcd = __gcd(nums[i],nums[j]);
                        int temp = setbit*gcd;
                        mx = max(mx,temp+solve(nums,dp,mask|(1<<i)|(1<<j)));
                    }
                }
            }
        }
        return dp[mask] = mx;
    }
    
    int maxScore(vector<int>& nums) {
        n=nums.size();
        vector<int> dp((1<<14),-1);
        int mask = 0;
        return solve(nums,dp,mask);
    }
};