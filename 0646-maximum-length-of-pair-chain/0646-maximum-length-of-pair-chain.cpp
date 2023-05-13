class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i,int prev,vector<vector<int>>& pairs){
        if(i>=pairs.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int notPick = solve(i+1,prev,pairs);
        int pick = 0;
        if(prev==-1 or pairs[i][0]>pairs[prev][1]) pick = 1+solve(i+1,i,pairs);
        return dp[i][prev+1] = max(pick,notPick);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs),end(pairs));
        int n = pairs.size();
        dp.resize(n,vector<int>(n+1,-1));
        return solve(0,-1,pairs);
    }
};