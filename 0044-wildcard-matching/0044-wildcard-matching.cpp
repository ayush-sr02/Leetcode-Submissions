class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i,int j,string &s,string &t){
        if(i<0 and j<0) return true;
        if(i<0){
            for(int k=j;k>=0;k--) if(t[k]!='*') return false;
            return true;
        }
        if(j<0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = solve(i-1,j-1,s,t);
        else{
            if(t[j]=='?'){
                return dp[i][j] = solve(i-1,j-1,s,t);
            }
            if(t[j]=='*') return dp[i][j] = solve(i-1,j,s,t) or solve(i,j-1,s,t);
            return dp[i][j] = 0;
        }
    }
    
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        dp.resize(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,p);
    }
};