class Solution {
public:
    
    void dfs(int row,int col,vector<vector<int>>&h,vector<vector<int>> &vis,int prev){
        int n=h.size();
        int m=h[0].size();
        if(row<0 || row>=n || col<0 || col>=m || vis[row][col] || h[row][col]<prev) return;
        vis[row][col]=1;
        dfs(row-1,col,h,vis,h[row][col]);
        dfs(row+1,col,h,vis,h[row][col]);
        dfs(row,col-1,h,vis,h[row][col]);
        dfs(row,col+1,h,vis,h[row][col]);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> p(n,vector<int> (m,0));
        vector<vector<int>> a(n,vector<int> (m,0));
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            dfs(0,i,heights,p,heights[0][i]);
            dfs(n-1,i,heights,a,heights[n-1][i]);
        }
        for(int i=0;i<n;i++){
            dfs(i,0,heights,p,heights[i][0]);
            dfs(i,m-1,heights,a,heights[i][m-1]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j]==1 && a[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};

