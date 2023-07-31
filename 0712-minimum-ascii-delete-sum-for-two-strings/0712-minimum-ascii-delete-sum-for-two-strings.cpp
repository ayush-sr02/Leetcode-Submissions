class Solution {
public:
    
    int solve(int i,int j,string &s,string &t,vector<vector<int>>& dp){
        if(i<0){
            int cnt=0;
            for(int k=j;k>=0;k--) cnt+=t[k];
            return cnt;
        }
        if(j<0){
            int cnt=0;
            for(int k=i;k>=0;k--) cnt+=s[k];
            return cnt;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = solve(i-1,j-1,s,t,dp);
        return dp[i][j] = min(s[i]+solve(i-1,j,s,t,dp),t[j]+solve(i,j-1,s,t,dp));
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(n-1,m-1,s1,s2,dp);
    }
};