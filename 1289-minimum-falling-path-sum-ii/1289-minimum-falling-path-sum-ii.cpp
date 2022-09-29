class Solution {
public:
    int solve(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp){
        if(j<0  or j==matrix.size()) return 1e9;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        // int up = matrix[i][j]+solve(matrix,i-1,j,dp);
        // int left=1e9;
        // if(j>0) left = matrix[i][j]+solve(matrix,i-1,j-1,dp);
        // int right=1e9;
        // if(j<matrix.size()-1) right = matrix[i][j]+solve(matrix,i-1,j+1,dp);
        int ans=1e9;
        for(int x=0;x<matrix.size();x++){
            if(x!=j){
                int temp = matrix[i][j] + solve(matrix,i-1,x,dp);
                ans=min(ans,temp);
            }
        }
        return dp[i][j] = ans;
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