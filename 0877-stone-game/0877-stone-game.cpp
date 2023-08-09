class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&piles,int i,int j,int alice){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(alice) return dp[i][j]=max(piles[i]+solve(piles,i+1,j,!alice),piles[j]+solve(piles,i,j-1,!alice));
        return dp[i][j]=min(-piles[i]+solve(piles,i+1,j,!alice),-piles[j]+solve(piles,i,j-1,!alice));
    }
    
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.resize(n,vector<int> (n,-1));
        return solve(piles,0,n-1,1)>0;
    }
};