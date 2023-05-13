class Solution {
public:
    #define ll long long
    
    ll solve(int i,vector<vector<int>>&q,vector<ll>&dp){
        if(i>=q.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        ll notPick = solve(i+1,q,dp);
        ll pick = 1ll*q[i][0];
        pick+=solve(i+1+q[i][1],q,dp);
        return dp[i] = max(pick,notPick);
    }
    
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<ll> dp(n,-1);
        return solve(0,q,dp);
    }
};