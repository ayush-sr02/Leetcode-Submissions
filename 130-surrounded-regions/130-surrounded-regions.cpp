class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board){
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size()) return;
        if(board[i][j]!='O') return;
        if(board[i][j]=='O')
            board[i][j]='1';
        
        dfs(i+1,j,board);
        dfs(i,j+1,board);
        dfs(i-1,j,board);
        dfs(i,j-1,board);  
}
    
    
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O'){
                   dfs(i,j,board);
               }
           }
       } 
         for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(board[i][j]=='O')
                   board[i][j]='X';
               if(board[i][j]=='1')
                    board[i][j]='O';
               }
           }
       }
};