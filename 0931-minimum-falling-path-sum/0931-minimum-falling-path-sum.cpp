class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>> &dp){
        if(i<0 or j<0 or j>matrix.size()-1) return 1e5;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = matrix[i][j]+solve(i-1,j,matrix,dp);
        int left = matrix[i][j]+solve(i-1,j-1,matrix,dp);
        int right = matrix[i][j]+solve(i-1,j+1,matrix,dp);
        return dp[i][j] = min({up,left,right});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=1e5;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        for(int i=0;i<n;i++){
            ans=min(ans,solve(n-1,i,matrix,dp));
        }
        return ans;
    }
};