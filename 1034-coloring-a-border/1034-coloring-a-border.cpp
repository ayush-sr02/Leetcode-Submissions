class Solution {
public:
    
    // a node is a part of the component only if it is the same color as required and shares a boundary with a node which is not a part of the component OR it is a boundary element
    int original ;
    
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int i,int j,int color){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or vis[i][j]) return;
        if(grid[i][j]!=original) return;
        vis[i][j]=1;
        if(i==0 or j==0 or i==grid.size()-1 or j==grid[0].size()-1) grid[i][j]=color;
        else if(grid[i-1][j]!=original and !vis[i-1][j]) grid[i][j]=color;
        else if(grid[i+1][j]!=original and !vis[i+1][j]) grid[i][j]=color;
        else if(grid[i][j-1]!=original and !vis[i][j-1]) grid[i][j]=color;
        else if(grid[i][j+1]!=original and !vis[i][j+1]) grid[i][j]=color;
        dfs(grid,vis,i-1,j,color);
        dfs(grid,vis,i+1,j,color);
        dfs(grid,vis,i,j-1,color);
        dfs(grid,vis,i,j+1,color);

    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        original = grid[row][col];
        dfs(grid,vis,row,col,color);
        return grid;
    }
};