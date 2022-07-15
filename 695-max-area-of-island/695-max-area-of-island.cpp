class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>&grid,int &x){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
        if(grid[i][j]==0) return ;
        grid[i][j]=0;
        x++;
        dfs(i+1,j,grid,x);
        dfs(i,j+1,grid,x);
        dfs(i-1,j,grid,x);
        dfs(i,j-1,grid,x);

    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int x=0;
                    dfs(i,j,grid,x);
                    ans=max(ans,x);
                }
            }
        }
        return ans;
    }
};