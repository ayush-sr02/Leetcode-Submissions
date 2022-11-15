class Solution {
public:
    
    // int solve(int i,int j,string &text1,string &text2,vector<vector<int>>&dp){
    //     if(i==text1.size() or j==text2.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(text1[i]==text2[j]) return dp[i][j] = 1+solve(i+1,j+1,text1,text2,dp);
    //     return dp[i][j]=max(solve(i+1,j,text1,text2,dp),solve(i,j+1,text1,text2,dp));
    // }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1));
        
        //Base Case
        for(int i=0;i<=text1.size();i++) dp[i][0]=0;
        for(int i=0;i<=text2.size();i++) dp[0][i]=0;
        
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};