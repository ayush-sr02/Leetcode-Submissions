class Solution {
public:
    
    vector<pair<int,int>> movement = {{0,-1},{0,1},{1,0},{-1,0}};

    bool valid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    void bfs(int i,int j,int n,int m,vector<vector<char>>& board){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            board[x][y] = 'a';
            for(auto it:movement){
                int xd = x+it.first;
                int yd = y+it.second;
                if(valid(xd,yd,n,m) and board[xd][yd]=='O'){
                    q.push({xd,yd});
                    board[xd][yd]='a';      // to avoid repetition of call for same point
                }
            }
        }
    }
    
    void dfs(int i,int j,int n,int m,vector<vector<char>>& board){
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]=='X') return;
        if(board[i][j]!='O') return;
        board[i][j]='a';
        dfs(i-1,j,n,m,board);
        dfs(i+1,j,n,m,board);
        dfs(i,j-1,n,m,board);
        dfs(i,j+1,n,m,board);

    }
    
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 or i==n-1 or j==0 or j==m-1) and board[i][j]=='O'){
                    bfs(i,j,n,m,board);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='a') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};