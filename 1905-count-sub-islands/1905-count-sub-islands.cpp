class Solution {
public:
    
    vector<pair<int,int>> movement = {{0,1},{0,-1},{-1,0},{1,0}};
    
    bool valid(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid1,vector<vector<int>>& grid2,bool &flag){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(auto it:movement){
                int x=a+it.first;
                int y=b+it.second;
                if(valid(x,y,n,m)){
                    if(grid2[x][y]==1 and grid1[x][y]==0) flag=false;
                    if(grid2[x][y]==1){
                        q.push({x,y});
                        grid2[x][y]=0;
                    }
                }
            }
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 and grid1[i][j]==1){
                    bool flag=true;
                    dfs(i,j,n,m,grid1,grid2,flag);
                    if(flag) cnt++;
                }
            }
        }
        return cnt;
    }
};