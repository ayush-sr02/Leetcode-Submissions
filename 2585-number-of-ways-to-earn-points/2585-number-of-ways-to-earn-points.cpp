class Solution {
public:
    int mod=1e9+7; 
    vector<vector<vector<int>>> dp;
    
    int solve(int i,int j,vector<vector<int>> &types,int target){
        if(i>=types.size() or j>types[i][0]) return 0;
        if(target==0) return 1;
        if(dp[i][j][target]!=-1) return dp[i][j][target];
        int notPick = solve(i+1,0,types,target)%mod;
        int pick = 0;
        if(target>=types[i][1]){
            pick = solve(i,j+1,types,target-types[i][1])%mod;
        }
        return dp[i][j][target]=(pick+notPick)%mod;
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();
        dp.resize(n,vector<vector<int>>(51,vector<int>(target+1,-1)));
        return solve(0,0,types,target);
    }
};