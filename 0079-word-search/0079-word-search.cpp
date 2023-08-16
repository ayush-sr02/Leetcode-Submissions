class Solution {
public:
    
    bool solve(int i,int j,int n,int m,vector<vector<char>>& board, string &word,int idx,vector<vector<int>> &vis){
        if(idx==word.size()) return true;
        if(i<0 or j<0 or i>=n or j>=m or vis[i][j] or board[i][j]!=word[idx]) return false;
        vis[i][j]=1;
        bool a = solve(i+1,j,n,m,board,word,idx+1,vis); 
        bool b = solve(i-1,j,n,m,board,word,idx+1,vis); 
        bool c = solve(i,j+1,n,m,board,word,idx+1,vis); 
        bool d = solve(i,j-1,n,m,board,word,idx+1,vis);
        vis[i][j]=0;
        if(a or b or c or d) return true;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j] and !vis[i][j]){
                    if(solve(i,j,n,m,board,word,0,vis)) return true;
                }
            }
        }
        return false;
    }
};