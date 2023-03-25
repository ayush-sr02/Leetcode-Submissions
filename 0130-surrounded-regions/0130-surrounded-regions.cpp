class Solution {
private:
    vector<int> dir={-1,0,+1,0,-1};
    int n,m;
    void dfs(int row,int col,vector<vector<char>>& mat,vector<vector<int>>& vis){
        if(row<0 or col<0 or row>=n or col>=m or vis[row][col] or mat[row][col]!='O') return;
        vis[row][col]=1;
        dfs(row-1,col,mat,vis);
        dfs(row+1,col,mat,vis);
        dfs(row,col-1,mat,vis);
        dfs(row,col+1,mat,vis);
    }
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> mat=board;
        n=mat.size();
        m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++){
            if(!vis[0][j] && mat[0][j]=='O')
                dfs(0,j,mat,vis);
            if(!vis[n-1][j] && mat[n-1][j]=='O')
                dfs(n-1,j,mat,vis);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0]=='O')
                dfs(i,0,mat,vis);
            if(!vis[i][m-1] && mat[i][m-1]=='O')
                dfs(i,m-1,mat,vis);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O')
                    mat[i][j]='X';
            }
        }
        board=mat;
    }
};
