class Solution {
public:
    
    int solve(string &s,int i,vector<int>&dp){
        if(i<0) return 1;
        if(dp[i]!=-1) return dp[i];
        int one = 0;
        if(s[i]!='0') one=solve(s,i-1,dp);
        int two = 0;
        if(i>0){
            if((s[i-1]=='2' and s[i]<='6') or (s[i-1]=='1')) two=solve(s,i-2,dp);
        }
        return dp[i]=one+two;
    }
    
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(s,n-1,dp);
    }
};