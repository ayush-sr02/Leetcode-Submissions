class Solution {
public:
    int dp[20001];
    
    int solve(int i,unordered_map<int,int>&mp){
        if(i>=20001) return 0;
        if(dp[i]!=-1) return dp[i];
        int notPick = solve(i+1,mp);
        int pick = (i*mp[i])+solve(i+2,mp);
        return dp[i]=max(pick,notPick);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;
        return solve(0,mp);
    }
};