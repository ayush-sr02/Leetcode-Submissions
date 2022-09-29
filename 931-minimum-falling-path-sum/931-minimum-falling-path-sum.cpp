class Solution {
public:
    
    int solve(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp){
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = matrix[i][j]+solve(matrix,i-1,j,dp);
        int left=1e9;
        if(j>0) left = matrix[i][j]+solve(matrix,i-1,j-1,dp);
        int right=1e9;
        if(j<matrix.size()-1) right = matrix[i][j]+solve(matrix,i-1,j+1,dp);
        return dp[i][j] = min(up,min(left,right));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=1e9;
        vector<vector<int>> dp(n,vector<int> (n,-1));

        for(int j=0;j<n;j++){
            int x=solve(matrix,n-1,j,dp);
            ans=min(x,ans);
        }
        return ans;
    }
};