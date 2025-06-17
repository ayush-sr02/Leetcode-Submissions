class Solution {
public:

    void solve(int i,int j,vector<vector<char>>&grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='0') return;
        grid[i][j]='0';
        solve(i+1,j,grid);
        solve(i-1,j,grid);
        solve(i,j+1,grid);
        solve(i,j-1,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    solve(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};