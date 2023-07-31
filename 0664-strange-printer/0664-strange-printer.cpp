class Solution {
public:
    
    int solve(int i,int j,string &s,vector<vector<int>> &dp){
        if(i==j) dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j] or s[j]==s[j-1]) return dp[i][j] = solve(i,j-1,s,dp);
        if(s[i]==s[i+1]) return dp[i][j] = solve(i+1,j,s,dp);
        int ans=1+solve(i,j-1,s,dp);
        for(int k=i+1;k<j;k++){
            if(s[j]==s[k]) ans=min(ans,solve(i,k-1,s,dp)+solve(k,j-1,s,dp));
        }
        return dp[i][j] = ans;
    }
    
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(0,n-1,s,dp);
    }
};