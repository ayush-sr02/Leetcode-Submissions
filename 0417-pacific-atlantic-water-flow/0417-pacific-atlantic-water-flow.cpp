class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>&heights,int i,int j,vector<vector<int>>&vis){
        if(i<0 or j<0 or i>=heights.size() or j>=heights[0].size() or vis[i][j]) return;
        vis[i][j]=1;
        if(i-1>=0 and !vis[i-1][j] and heights[i-1][j]>=heights[i][j]) dfs(heights,i-1,j,vis);
        if(i+1<n and !vis[i+1][j] and heights[i+1][j]>=heights[i][j]) dfs(heights,i+1,j,vis);
        if(j-1>=0 and !vis[i][j-1] and heights[i][j-1]>=heights[i][j]) dfs(heights,i,j-1,vis);
        if(j+1<m and !vis[i][j+1] and heights[i][j+1]>=heights[i][j]) dfs(heights,i,j+1,vis);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        n=heights.size(),m=heights[0].size();
        vector<vector<int>> atl(n,vector<int> (m,0));
        vector<vector<int>> pac(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0){
                    dfs(heights,i,j,pac);
                }
                if(i==n-1 or j==m-1){
                    dfs(heights,i,j,atl);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]==1 and atl[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};