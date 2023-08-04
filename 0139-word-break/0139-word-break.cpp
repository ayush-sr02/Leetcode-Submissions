class Solution {
public:
    
    vector<vector<int>> dp;
    
    bool solve(int i,int j,string& s,set<string>& st){
        if(i==s.size()) return 1;
        if(j==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        bool notPick = solve(i,j+1,s,st);
        bool pick=false;
        string temp = s.substr(i,j-i+1);
        if(st.count(temp)) pick = solve(j+1,j+1,s,st);
        return dp[i][j] = pick or notPick;
    }
    
    bool wordBreak(string s, vector<string>& w) {
        int n=s.size();
        dp.resize(n,vector<int> (n,-1));
        set<string> st(begin(w),end(w));
        return solve(0,0,s,st);
    }
};