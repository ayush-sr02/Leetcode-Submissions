class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int time,vector<int>&v){
        if(i>=v.size()) return 0;
        if(dp[i][time]!=-1) return dp[i][time];
        int notPick = solve(i+1,time,v);
        int pick = time*v[i]+solve(i+1,time+1,v);
        return dp[i][time] = max(pick,notPick);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        dp.resize(n,vector<int> (n+1,-1));
        sort(begin(satisfaction),end(satisfaction));
        return solve(0,1,satisfaction);
    }
};