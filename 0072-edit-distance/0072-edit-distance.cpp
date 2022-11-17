class Solution {
public:
    
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        
        if(i<0) return j+1;
        if(j<0) return i+1; 
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j] = solve(i-1,j-1,s,t,dp);
        else{
            int insert = 1+solve(i,j-1,s,t,dp);     // when inserting a character, i will remain at the same position but j will move back because we are matching it with the inserting character.
            
            int del = 1+solve(i-1,j,s,t,dp);        // when deleting a char, i will move back as that char is discarded and then the prev s[i] will be compared to the same t[j].
            
            int replace = 1+solve(i-1,j-1,s,t,dp);  // when replacing, both the chars will be matched so both will move back.
            return dp[i][j] = min(insert,min(del,replace));
        }
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(n-1,m-1,word1,word2,dp);
    }
};