class Solution {
public:
    vector<vector<int>> dp;
    
    bool solve(int i,int j,string &s,string &p){
        if(i<0 and j<0) return true;
        if(i<0 and j>=0){
            for(int x=0;x<=j;x++) if(p[x]!='*') return false;
            return true;
        }
        if(j<0 and i>=0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==p[j] or p[j]=='?') return dp[i][j] = solve(i-1,j-1,s,p);
        else if(p[j]=='*'){
            return dp[i][j] = solve(i-1,j,s,p) or solve(i,j-1,s,p);
        }
        else return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        dp.resize(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,p);
    }
};